#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;


int graph[11][11];
int N;
int result = 0;



void check(int i, int j) {
	int dir[4][2] = { { -1,-1 }, { 1, 1 }, { -1, 1 }, { 1, -1 } };
	for (int i1 = 0; i1 < 4; i1++) {
		int ni = i; int nj = j;
		while (1) {
			ni += dir[i1][0];
			nj += dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= N)
				break;

			graph[ni][nj] = 0;
		}
	}
}

void recursion(int depth, int index) {

	for (int i1 = index; i1 < N * N; i1++) {
		int i = i1 / N;
		int j = i1 % N;
		if (graph[i][j] == 1) {
			graph[i][j] = 0;
			check(i, j);
			recursion(depth + 1, i * N + j + 1);
			graph[i][j] = 1;
		}

	}

	result = max(result, depth);
}
int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	recursion(0, 0);

	cout << result;
	//system("Pause");
}
