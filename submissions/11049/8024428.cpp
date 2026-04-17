#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;
int dp[600][600];
int N1[501][2];
int N2[600][600];


void minmulti() {
	for (int i = 2; i <= N; i++) {
		for (int i1 = i - 1; i1 >= 1; i1--) {
			N2[i1][i] = N1[i1 - 1][0] * 10 + N1[i - 1][1];						
			for (int j1 = i1; j1 < i; j1++) {
				int a = dp[i1][j1] + dp[j1+1][i] + (N2[i1][j1] / 10)*(N2[i1][j1] % 10) * (N2[j1 + 1][i] % 10);
				if (dp[i1][i] == 0)
					dp[i1][i] = a;
				else if (dp[i1][i] > a)
					dp[i1][i] = a;

			}
		}
	}
	
}


int main() {
	cin >> N;
	int r;
	int c;

	for (int i = 0; i < N; i++) {
		cin >> r >> c;
		N1[i][0] = r;
		N1[i][1] = c;
	}


	for (int i = 1; i <= N-1; i++) {
		dp[i][i + 1] = N1[i - 1][0] * N1[i - 1][1] * N1[i][1];
	}

	for (int i = 1; i <= N; i++) {
		N2[i][i] = N1[i - 1][0] * 10 + N1[i - 1][1];
	}



	minmulti();

	cout << dp[1][N];


}