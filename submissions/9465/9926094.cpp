#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <memory.h>
using namespace std;

int n1[100001][2];
int T;
int n;
int DP[100001][2];
int dpdp(int n) {
	int result = 0;
	DP[0][0] = n1[0][0];
	DP[0][1] = n1[0][1];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				DP[i][j] = max(DP[i][j], DP[i - 1][j + 1]+n1[i][j]);
				if (i - 2 >= 0) {
					DP[i][j] = max(DP[i][j], DP[i - 2][0] + n1[i][j]);
					DP[i][j] = max(DP[i][j], DP[i - 2][1] + n1[i][j]);
				}

			}
			if (j == 1) {
				DP[i][j] = max(DP[i][j], DP[i - 1][j - 1] + n1[i][j]);
				if (i - 2 >= 0) {
					DP[i][j] = max(DP[i][j], DP[i - 2][0] + n1[i][j]);
					DP[i][j] = max(DP[i][j], DP[i - 2][1] + n1[i][j]);
				}

			}
			result = max(result, DP[i][j]);

		}
	}
	return result;
}

int main() {
	cin >> T;




	for (int i = 0; i < T; i++) {
		scanf("%d", &n);


		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &n1[j][i]);
			}
		}
		printf("%d\n", dpdp(n));

		memset(n1, 0, sizeof(n1));
		memset(DP, 0, sizeof(DP));

	}

}