#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int dp[10000001];
int birth[10000001];
int a, b, d, N;


void recursion() {
	for (int i = 1; i <= N; i++) {
		if (i < a)
			birth[i] = 0;
		else if (i >= a && i < b) {
			birth[i] = dp[i - a];
		}
		else if (i >= a && i >= b) {
			birth[i] = (dp[i - a] - dp[i - b]+1000) % 1000;
		}

		dp[i] = (dp[i - 1] + birth[i]) % 1000;
	}
}


int main() {
	cin >> a >> b >> d >> N;

	birth[0] = 1;
	dp[0] = 1;


	recursion();

	int result = 0;



	for (int i = N; i > N - d; i--) {
		result = (result + birth[i]) % 1000;
	}
	cout << result;
}