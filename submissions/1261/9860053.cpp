#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
int graph[101][101];
int dirx[4] = { 0,0,-1,1 };
int diry[4] = { -1,1,0,0 };
bool check[101][101];
int result = -1;


void dfs(int x, int y, int count) {

	if (x == N - 1 && y == M - 1) {
		if (result == -1)
			result = count;
		else
			result = min(result, count);
		
		return;

	}
	else if (result !=-1 && count > result)
		return;

	for (int i1 = 0; i1 < 4; i1++) {
		int nx = x + dirx[i1];
		int ny = y + diry[i1];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;
		if (check[nx][ny] == false) {
			check[nx][ny] = true;
			dfs(nx, ny, count + graph[nx][ny]);
			check[nx][ny] = false;
		}

	
	}
}




int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &graph[i][j]);

		}
	}


	check[0][0] = true;
	dfs(0, 0,0);
	cout << result;



}