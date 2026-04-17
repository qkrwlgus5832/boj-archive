#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;


long long dp[2000];


void recursion(int N) {

	if (N == 1) {
		dp[0] = 1;
		return;
	}
	else if (N == 2) {
		recursion(N - 1);
		dp[1] = 2;
		return;
	}
	else if (N == 3) {
		recursion(N - 1);
		dp[2] = 3;
		return;
	}
	else if (N == 4) {
		recursion(N - 1);
		dp[3] = 5;
		return;
	}
	else {
		recursion(N - 1);
		dp[N - 1] = dp[N - 2] * 2 - dp[N - 3] + dp[N - 5];
	}


}




int n;
int main() {
	cin >> n;

	recursion(n);

	cout << dp[n - 1]%10007;



}
