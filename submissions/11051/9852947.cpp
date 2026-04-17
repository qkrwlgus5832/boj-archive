#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N, K;
int dp[1001][1001];
int main() {

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)
				dp[i][j] = i;

			else if (i == j) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%10007;
			}


		}
	}
	cout << dp[N][K];


}