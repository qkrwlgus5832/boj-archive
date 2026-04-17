#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;


int N;
int graph[101][101];
bool check[101][101];
int dir[4][2] = { { -1, 0 }, {1,0},{0,-1},{0,1} };

void BFS1(int i, int j, int numbering) {
	queue <pair <int, int>> q;
	q.push(make_pair(i, j));
	check[i][j] = true;
	graph[i][j] = numbering;
	while (!q.empty()) {
		int fronti = q.front().first;
		int frontj = q.front().second;

		q.pop();

		for (int i1 = 0; i1 < 4; i1++) {
			int ni = fronti + dir[i1][0];
			int nj = frontj + dir[i1][1];
			if (ni < 0 || nj < 0 || ni >= N || nj >= N)
				continue;
			if (check[ni][nj] == false && graph[ni][nj] == 1) {
				check[ni][nj] = true;
				graph[ni][nj] = numbering;
				q.push(make_pair(ni, nj));
			}

		}
	}
}


int BFS2(int i, int j) {
	queue <pair <int, int>> q;
	q.push(make_pair(i, j));
	bool check[101][101] = { false, };
	check[i][j] = true;
	int count = 0;
	while (!q.empty()) {
		int s = q.size();
		for (int qindex = 0; qindex < s; qindex++) {
			int fronti = q.front().first;
			int frontj = q.front().second;

			q.pop();

			for (int i1 = 0; i1 < 4; i1++) {
				int ni = fronti + dir[i1][0];
				int nj = frontj + dir[i1][1];
				if (ni < 0 || nj < 0 || ni >= N || nj >= N)
					continue;
				if (check[ni][nj] == false && graph[ni][nj] == 0) {
					check[nj][nj] = true;
					q.push(make_pair(ni, nj));
				}
				else if (graph[ni][nj] != 0 && graph[i][j] != graph[ni][nj]) {
					return count;
				}

			}
		}
		count++;
	}
	return -1;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	int numbering = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == false && graph[i][j] == 1) {
				BFS1(i, j, numbering);
				numbering++;
			}
		}
	}


	int result = INT_MAX;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] !=0) {
				int bfsresult = BFS2(i, j);
				if (bfsresult != -1)
					result = min(result, bfsresult);
			}
		}
	}
	cout << result;
	//system("Pause");
}