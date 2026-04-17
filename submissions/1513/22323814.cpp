#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arcade[51][51];
long long dp[51][51][51][51];

int main() {
	int N, M, C;
	cin >> N >> M >> C;

	int x, y;
	for (int i = 0; i < C; i++) {
		scanf("%d %d", &x, &y);
		arcade[x- 1][y- 1] = i + 1;
	}

	if (arcade[0][0] > 0) {
		dp[0][0][arcade[0][0]][1] = 1;
	}
	else {
		dp[0][0][0][0] = 1;
	}

	for (int l = 0; l <= C; l++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arcade[i][j] > 0) {
					if (i > 0 && l > 0) {
						for (int k1 = 0; k1 < arcade[i][j]; k1++) {
							dp[i][j][arcade[i][j]][l] += dp[i - 1][j][k1][l - 1];
							dp[i][j][arcade[i][j]][l] %= 1000007;
						}
					}
					if (j > 0 && l > 0) {
						for (int k1 = 0; k1 < arcade[i][j]; k1++) {
							dp[i][j][arcade[i][j]][l] += dp[i][j - 1][k1][l - 1];
							dp[i][j][arcade[i][j]][l] %= 1000007;
						}
					}
				}
				else {
					if (i > 0) {
						for (int k1 = 0; k1 <= C; k1++) {
							dp[i][j][k1][l] += dp[i - 1][j][k1][l];
							dp[i][j][k1][l] %= 1000007;
						}

					}
					if (j > 0) {
						for (int k1 = 0; k1 <= C; k1++) {
							dp[i][j][k1][l] += dp[i][j - 1][k1][l];
							dp[i][j][k1][l] %= 1000007;
						}
					}
				}
			}

		}
	}
	for (int i = 0; i <= C; i++) {
		long long sum = 0;

		for (int j = 0; j <= C; j++) {
			sum = (sum + dp[N - 1][M - 1][j][i]) % 1000007;
		}
		cout << sum % 1000007 << " ";
	}
	//system("Pause");
}
