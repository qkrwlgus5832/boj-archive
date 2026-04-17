#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <iostream>
using namespace std;

int graph[501][501];
int DP[501][501];
int M, N;

int dirx[4] = {1,0,0,-1};
int diry[4] = {0,-1,1,0};

int dfs(int x, int y) {
	int count = 0;
	if (x == M - 1 && y == N - 1) {
		return 1;
	}

	for (int i1 = 0; i1 < 4; i1++) {
		int nx = x+ dirx[i1];
		int ny = y + diry[i1];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;

	
		if (graph[x][y] > graph[nx][ny] ) {
			if (DP[nx][ny] < 0) {
				int result = dfs(nx, ny);
				count += result;
			}
			else {
				count +=DP[nx][ny];
			}
		}
	

	}

	DP[x][y] = count;

	return DP[x][y];

}
int main() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	memset(DP, -1, sizeof(DP));
	dfs(0, 0);

	cout << DP[0][0];

}