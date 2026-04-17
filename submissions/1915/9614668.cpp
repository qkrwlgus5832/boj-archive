#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001];
int dpdp() {
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i - 1 < 0 || j - 1 < 0)
				dp[i][j] = arr[i][j];

			else if (arr[i][j] == 1) {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
				dp[i][j] = dp[i][j] + 1;
			}

			else if (arr[i][j] == 0)
				dp[i][j] = 0;

			result = max(result, dp[i][j]);
		}
	}

	return result*result;

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}





	cout << dpdp();


}