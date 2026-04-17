#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>

using namespace std;

int N, M;
int x, y, K;

int rotatedSide[4][6] = {
	{2, 1, 5, 0, 4, 3},
	{3, 1, 0, 5, 4, 2},
	{1, 5, 2, 3, 0, 4},
	{4, 0, 2, 3, 5, 1}
};

int dir[7];

int graph[21][21];

int direction_[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };

//int currentSide = 5;

int dice(int direction) {
	int ni = x + direction_[direction][0];
	int nj = y + direction_[direction][1];
	if (ni < 0 || nj < 0 || ni >= N || nj >= M)
		return -1;
	x = ni; y = nj;

	int tmpdir[7] = { 0, };
	
	memcpy(tmpdir, dir, sizeof(dir));

	for (int i = 0; i < 6; i++) {
		dir[i] = tmpdir[rotatedSide[direction][i]];
	}
	int currentSide = dir[5];
	
	if (graph[ni][nj] == 0) {
		graph[ni][nj] = dir[5];
	}
	else {
		dir[5] = graph[ni][nj];
		graph[ni][nj] = 0;
	}
	return dir[0];
}



int main() {

	cin >> N >> M >> x >> y >> K;
	int tmp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);

		}
	}

	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);
		int result = dice(tmp -1);
		if (result != -1)
			printf("%d\n", result);
	}
	//system("Pause");
}