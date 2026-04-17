#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <limits.h>
using namespace std;

int N;
int origin[100001][3];
int DP[100001][3];

void setDP_MAX(pair <int, int> prev, pair <int, int> current) {
	int currentvalue = origin[current.first][current.second];
	DP[current.first][current.second] = max(DP[prev.first][prev.second] + currentvalue, currentvalue);
}

void setDP_MIN(pair <int, int> prev, pair <int, int> current) {
	int currentvalue = origin[current.first][current.second];
	DP[current.first][current.second] = min(DP[prev.first][prev.second] + currentvalue, DP[current.first][current.second]);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &origin[i][j]);
		}
	}
	memcpy(DP, origin, sizeof(origin));

	for (int i = 0; i < N -1 ; i++) {
		for (int j = 0; j < 3; j++) {
			for (int aid = -1; aid <= 1; aid++) {
				if (j + aid < 0 || j + aid >= 3)
					continue;
				setDP_MAX({ i,j }, { i + 1, j + aid });
			}
		}
	}
	int maxvalue = 0;
	for (int i = 0; i < 3; i++) {
		maxvalue = max(DP[N - 1][i], maxvalue);
	}

	for (int i = 0; i < N -1; i++) {
		for (int j = 0; j < 3; j++) {
			//DP[i + 1][j] += DP[i][j];
			for (int aid = -1; aid <= 1; aid++) {
				if (j + aid < 0 || j + aid >= 3)
					continue;
				setDP_MIN({ i,j }, { i + 1, j + aid });
			}
		}
	}
	int minvalue = INT_MAX;
	for (int i = 0; i < 3; i++) {
		minvalue = min(DP[N - 1][i], minvalue);
	}

	cout << maxvalue << " " << minvalue;
	//system("Pause");
}