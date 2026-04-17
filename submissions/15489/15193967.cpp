#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int dp[100][100];
int main() {
	int R, C, W;
	cin >> R >> C >> W;

	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= R + W; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	//for (int i = 0; i < R + W; i++) {
	//	for (int j = 0; j <= i; j++) {
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	//cout << endl;
	int result = 0;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j <= i; j++) {
			result += dp[R - 1 + i][C - 1 + j];
		}
	}
	cout << result; 
	//system("Pause");
}