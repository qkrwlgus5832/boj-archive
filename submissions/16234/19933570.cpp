#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <queue>


using namespace std;


int graph[51][51];
bool check[51][51];
bool check2[51][51];


int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N, L, R;

void bfs(int i, int j) {
	check2[i][j] = true;
	queue <pair <int, int>> q;
	vector <pair <int, int>> tmp;

	q.push(make_pair(i, j));
	tmp.push_back(make_pair(i, j));

	int count = 1;
	int value = graph[i][j];

	while (q.size()) {
		pair <int, int> front = q.front();
		q.pop();

		for (int i1 = 0; i1 < 4; i1++) {
			int ni = front.first + dir[i1][0];
			int nj = front.second + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= N)
				continue;
			if (!check2[ni][nj] && check[ni][nj]) {
				check2[ni][nj] = true;
				q.push(make_pair(ni, nj));
				tmp.push_back(make_pair(ni, nj));
				count++;
				value += graph[ni][nj];
			}
		}
	}
	for (int i = 0; i < tmp.size(); i++) {
		graph[tmp[i].first][tmp[i].second] = value / count;
	}

}
bool peopleMovement() {
	memset(check, false, sizeof(check));
	memset(check2, false, sizeof(check2));

	bool flag = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i+1 < N && abs(graph[i + 1][j] - graph[i][j]) >= L && abs(graph[i + 1][j] - graph[i][j]) <= R) {
				check[i][j] = true;
				check[i + 1][j] = true;
				flag = true;
			}
			if (j+1 < N && abs(graph[i][j + 1] - graph[i][j]) >= L && abs(graph[i][j + 1] - graph[i][j]) <= R) {
				check[i][j] = true;
				check[i][j + 1] = true;
				flag = true;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check2[i][j] == false && check[i][j] == true) {
				bfs(i, j);
			}
		}
	}
	return flag;
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	int result = 0;
	while (1) {
		if (peopleMovement() == false) {
			cout << result;
			break;
		}
		result++;
	}
	//system("Pause");
}