#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>


long long dp[31][31];

using namespace std;


void dpdp() {
	for (int j = 1; j <= 30; j++) {
		for (int i = 1; i <= 30; i++) {
			if (i == 1) {
				dp[i][j] = j;
				continue;
			}
			else if (i == j) {
				dp[i][j] = 1;
			}
			else {
				for (int i1 = j - 1; i1 >= i-1; i1--) {
					dp[i][j] += dp[i - 1][i1];
				}
			}
		}
	}

}


int main() {
	int T;
	cin >> T;
	dpdp();

	int N, M;


	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		printf("%lld\n", dp[N][M]);
	}
}