#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int graph[501][501];
int DP[501][501];
int n;
int dirx[4] = { 0,0,-1,1 };
int diry[4] = { -1,1,0,0 };

void dp(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dirx[i];
		int ny = y + diry[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;
		

		if (graph[nx][ny] < graph[x][y]) {
			if (DP[nx][ny] == 0)
				dp(nx, ny);

			DP[x][y] = max(DP[x][y], DP[nx][ny]+1);
		}



	}

	if (DP[x][y] == 0)
		DP[x][y] = 1;


}


int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp(i, j);
		}
	}

	int result = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result = max(result, DP[i][j]);
		}
	
	}

	cout << result;
}