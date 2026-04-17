#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

int N; 

int dp[100001];

int main() {
	cin >> N;


	dp[1] = 3;
	dp[2] = 7;

	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] * 3 + 2;
	}

	cout << dp[N] % 9901;

}