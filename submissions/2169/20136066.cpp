#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int graph[1001][1001];
int N, M;

int dir[3][2] = { { 1,0 }, { 0, -1 }, {0,1} };

int result = INT_MIN;
int DP[1001][1001][3];


void recursion(int i, int j, int value, bool check[1001][1001]) {
	if (i == N - 1 && j == M - 1) {
		result = max(result, value);
		return;
	}
	for (int i1 = 0; i1 < 3; i1++) {
		int ni = i + dir[i1][0];
		int nj = j + dir[i1][1];

		if (ni < 0 || nj < 0 || ni >= N || nj >= M)
			continue;
		if (check[ni][nj])
			continue;
		if (DP[ni][nj][i1] > (value + graph[ni][nj]))
			continue;
		DP[ni][nj][i1] = value + graph[ni][nj];
		check[ni][nj] = true;
		recursion( ni, nj, value + graph[ni][nj], check);
		check[ni][nj] = false;
	}
}

int main() {


	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
			DP[i][j][0] = INT_MIN;
			DP[i][j][1] = INT_MIN;
			DP[i][j][2] = INT_MIN;
		}
	}
	bool check[1001][1001] = { false, };
	DP[0][0][2] = graph[0][0];
	check[0][0] = true;
	recursion(0, 0, graph[0][0], check);
	cout << result;
	//system("Pause");
}