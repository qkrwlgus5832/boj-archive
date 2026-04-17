#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;


char graph[51][51];

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int result = 0;
int N, M;

void recursion(int i, int j, bool check[51][51][4], int depth) {
	int count = graph[i][j] -'0';

	for (int i1 = 0; i1 < 4; i1++) {
		int ni = i + dir[i1][0] * count;
		int nj = j + dir[i1][1] * count;

		if (ni < 0 || nj < 0 || ni >= N || nj >= M) {
			result = max(result, depth + 1);
			continue;
		}
		else if (check[ni][nj][i1] == true) {
			cout << -1;
			exit(0);
		}
		else if (graph[ni][nj] == 'H') {
			result = max(result, depth + 1);
			continue;
		}
		check[ni][nj][i1] = true;
		recursion(ni, nj, check, depth + 1);
		check[ni][nj][i1] = false;
	}

}
int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];

		}
	}
	bool check[51][51][4] = { false, };

	recursion(0, 0, check, 0);
	cout << result;
	//system("Pause");
}