#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


long long dp[100][10][1 << 10];

int mod = 1000000000;

void dfs(int size, int number, int check) {
	
	if (size == 0) {
		if (number == 0)
			return;
		if (check == ((1 << 10) - 1))
			dp[size][number][check] = 1;
		return;
	}

	if (number == 9) {
		if (dp[size-1][8][check | (1 << 8)] == 0)
			dfs(size - 1, 8, check | (1 << 8));
		dp[size][9][check] += dp[size - 1][8][check | (1 << 8)];
	}
	else if (number == 0) {
		if (dp[size - 1][1][check | (1 << 1)] == 0)
			dfs(size - 1, 1, check | ( 1<< 1));
		dp[size][0][check] += dp[size - 1][1][check | (1 << 1)];
	}
	else {
		if (dp[size - 1][number-1][check | (1 << (number -1))] == 0)
			dfs(size - 1, number - 1, check | ( 1 << (number - 1)));
		if (dp[size - 1][number + 1][check | (1 << (number + 1))] == 0)
			dfs(size - 1, number + 1, check | ( 1 << (number + 1)));

		dp[size][number][check] += dp[size - 1][number - 1][check | (1 << (number - 1))] % mod;
		dp[size][number][check] += dp[size - 1][number + 1][check | (1 << (number + 1))] % mod;
	}

}
int main() {

	int N;
	cin >> N;

	long long ans = 0;

	for (int i = 0; i <= 9; i++) {
		dfs(N - 1, i, 1 << i);
		ans = (ans + dp[N - 1][i][1 << i]) % mod;
	}

	
	cout << ans;
	//system("Pause");
}
