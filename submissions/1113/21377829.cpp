#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;

int graph[51][51];
int answer[51][51];

int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

int checkMaxValue(int i, int j) {
	int height = 10;
	for (int i1 = 0; i1 < 4; i1++) {
		int count = 1;
		int maxValue = graph[i][j];
		while (1) {
			int ni = i + dir[i1][0] * count;
			int nj = j + dir[i1][1] * count;

			if (ni < 0 || nj < 0 || ni >= N || nj >= M)
				break;
			maxValue = max(maxValue, graph[ni][nj]);
			count++;
		}
		height = min(height, maxValue);
	}
	return height - graph[i][j];
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 || j == 0 || i == N - 1 || j == M - 1)
				continue;
			result += checkMaxValue(i, j);
		}
	}
	cout << result;

}