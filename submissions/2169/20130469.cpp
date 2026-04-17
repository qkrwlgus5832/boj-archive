#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int graph[1001][1001];
int N, M;

int dir[3][2] = { { 1,0 }, { 0, -1 }, {0,1} };

int result = 0;

void recursion(bool check[1001][1001], int i, int j, int value) {
	if (i == N - 1 && j == M - 1) {
		result = max(result, value);
		return;
	}
	for (int i1 = 0; i1 < 3; i1++) {
		int ni = i + dir[i1][0];
		int nj = j + dir[i1][1];

		if (ni < 0 || nj < 0 || ni >= N || nj >= M)
			continue;
		if (check[ni][nj] == true)
			continue;
		check[ni][nj] = true;
		recursion(check, ni, nj, value + graph[ni][nj]);
		check[ni][nj] = false;
	}
}

int main() {


	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	bool check[1001][1001] = { false, };
	recursion(check, 0, 0, graph[0][0]);
	cout << result;
	//system("Pause");
}