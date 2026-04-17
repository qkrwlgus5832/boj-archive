#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;


unsigned long long dp[2000];



int n;
int main() {
	cin >> n;

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 3;
	dp[3] = 5;

	if (n == 1)
		cout << 1 % 10007;
	else if (n == 2)
		cout << 2 % 10007;
	else if (n == 3)
		cout << 3 % 10007;
	else if (n == 4)
		cout << 5 % 10007;
	else {
		for (int i = 4; i < n; i++) {
			dp[i] = (dp[i - 1] +dp[i-2])  % 10007;
		}

		cout << dp[n - 1];
	}




}

