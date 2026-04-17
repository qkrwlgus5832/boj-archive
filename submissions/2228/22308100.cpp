#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


int dp[101][2][101];
vector <int> v;

void init() {
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 1; j++) {
			for (int k = 0; k <= 100; k++) {
				dp[i][j][k] = -4000000;
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	init();
	
	v.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	dp[0][1][1] = v[0];
	dp[0][0][0] = 0;

	for (int i = 1; i < N; i++) {
		for (int k = 0; k <= M; k++) {
			dp[i][0][k] = max(dp[i - 1][0][k], dp[i - 1][1][k]);
			if (k == 0)
				dp[i][1][k] = dp[i - 1][1][k] + v[i];
			else
				dp[i][1][k] = max(dp[i - 1][1][k] + v[i], dp[i - 1][0][k - 1] + v[i]);
		}
	}
	
	int result = -4000000;

	for (int i = 0; i < N; i++) {
		result = max(result, dp[i][0][M]);
		result = max(result, dp[i][1][M]);
	}

	cout << result;
	//system("Pause");
}
