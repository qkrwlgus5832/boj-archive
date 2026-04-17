#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int inputarray[301][301];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> inputarray[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= M; j++) {
			inputarray[i][j] += inputarray[i][j-1];
		}
	}

	int K;
	cin >> K;
	int i, j, x, y;

	for (int t = 0; t < K; t++) {
		scanf("%d %d %d %d", &i, &j, &x, &y);
		i--;
		x--;
		int sum = 0;
		for (int i1 = i; i1 <= x; i1++) {
			sum += inputarray[i1][y] - inputarray[i1][j - 1];
		}
		printf("%d\n", sum);
	}
	//system("Pause");
}