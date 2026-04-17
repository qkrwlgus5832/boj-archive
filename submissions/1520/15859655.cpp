#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>

using namespace std;

int graph[501][501];

map <pair <int, int>, int> m;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int M, N;

int DFS(int i, int j) {

	if (i == M - 1 && j == N - 1)
		return 1;

	if (m.count({ i, j }) != 0)
		return m[{i, j}];

	for (int i1 = 0; i1 < 4; i1++) {
		int ni = i + dir[i1][0];
		int nj = j + dir[i1][1];

		if (ni < 0 || nj < 0 || ni >= M || nj >= N)
			continue;
		
		if (graph[ni][nj] < graph[i][j])
			m[{i, j}] += DFS(ni, nj);
		
	}
	return m[{i, j}];
}



int main() {
	
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	cout << DFS(0, 0);
	//system("Pause");
}