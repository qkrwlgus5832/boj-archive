#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;


int N, L, R;

int N1[51][51];

vector <int> graph[2601];

bool check[51][51];
vector <pair <int, int>> v;

int BFS(int i, int j){
	queue <pair<int, int>> q;

	q.push(make_pair(i, j));
	v.push_back(make_pair(i, j));
	check[i][j] = true;
	int count = 1;
	int value = N1[i][j];

	while (!q.empty()) {
		int fronti = q.front().first;
		int frontj = q.front().second;
		q.pop();
		for (int i = 0; i < graph[fronti * N + frontj].size(); i++) {
			if (check[graph[fronti*N + frontj][i] / N][graph[fronti*N + frontj][i] % N] == false) {
				check[graph[fronti*N + frontj][i] / N][graph[fronti*N + frontj][i] % N] = true;
				q.push(make_pair(graph[fronti*N + frontj][i] / N, graph[fronti*N + frontj][i] % N));
				v.push_back(make_pair(graph[fronti*N + frontj][i] / N, graph[fronti*N + frontj][i] % N));
				value += N1[graph[fronti*N + frontj][i] / N][graph[fronti*N + frontj][i] % N];
				count++;
			}
		}

	}
	return value / count;
}

int checkintegration(int firsti, int firstj, int secondi, int secondj) {
	int comparevalue = abs(N1[secondi][secondj] - N1[firsti][firstj]);

	if (comparevalue >= L && comparevalue <= R) {
		graph[firsti * N + firstj].push_back(secondi * N + secondj);
		graph[secondi * N + secondj].push_back(firsti * N + firstj);
		return true;
	}
	else
		return false;
}

void set() {
	
	for (int i = 0; i < 2601; i++) {
		graph[i].clear();
	}
	for (int i = 0; i < 51; i++) {
		memset(check[i], 0, sizeof(check[i]));
	}

}
int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &N1[i][j]);
		}
	}
	int result = 0;

	while (1) {
		int f = 0;
		graph->resize(2601);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i + 1 < N)
					f += checkintegration(i, j, i + 1, j);
				if (j + 1 < N)
					f += checkintegration(i, j, i,  j + 1);

			}
		}
		if (f == 0)
			break;
		else
			result++;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] == false) {
					int result = BFS(i, j);
					for (int i1 = 0; i1 < v.size(); i1++) {
						N1[v[i1].first][v[i1].second] = result;
					}
				}
				v.clear();
			}
		}
	
		set();
		v.clear();

	}

	cout << result;
	//system("Pause");
}