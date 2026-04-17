#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;


long long dp[2000];






int n;
int main() {
	cin >> n;

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 3;
	if (n == 1)
		cout << "1";
	else if (n == 2)
		cout << "2";
	else if (n == 3)
		cout << "3";
	else {
		for (int i = 3; i < n; i++) {
			dp[i] = dp[i - 1] + dp[i - 1] - dp[i - 2] + dp[i - 4];
		}
	}


	cout << dp[n - 1]%10007;



}
