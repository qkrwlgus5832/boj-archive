#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

int N;

int dp[100001];

int main() {
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	if (N % 2 == 1) {
		cout << 0;


	}
	else {
		for (int i = 3; i <= N; i++) {
			dp[i] = dp[i - 2] + dp[i - 1];
		}

		cout << dp[N] * 2 - 1;
	}


}