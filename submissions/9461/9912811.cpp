#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;
long long dp[101] = {-1, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 , };
int N;

int main() {
	for (int i = 11; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	int T;
	cin >> T;
	int tmp;
	for (int i = 0; i < T; i++) {
		scanf("%d", &tmp);
		printf("%d\n", dp[tmp]);
	}

}