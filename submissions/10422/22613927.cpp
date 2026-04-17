#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int dp[5001];


int main() {
	int T;
	cin >> T;

	dp[1] = 1;

	for (int i = 2; i <= 2500; i++) {
		int sum = 0;
		for (int j = 1; j < i; j++) {
			sum = (sum + dp[j]) % 1000000007;
		}
		dp[i] = sum + 1;
	}

		int input;
	for (int i = 0; i < T; i++) {
		scanf("%d", &input);
		if (input % 2 != 0)
			printf("%d\n", 0);
		else
			printf("%d\n", dp[input / 2]);
	}

	//system("Pause");
}
