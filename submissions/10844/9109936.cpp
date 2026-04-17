#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

long long DP[101][10];
int N;
int main() {
	cin >> N;

	if (N == 1) {
		cout << 9;
	}
	else if (N == 2) {
		cout << 17;
	}
	else {
		DP[2][0] = 1;
		DP[2][1] = 2;
		DP[2][2] = 2;

		DP[2][3] = 2;

		DP[2][4] = 2;

		DP[2][5] = 2;

		DP[2][6] = 2;

		DP[2][7] = 2;

		DP[2][8] = 2;

		DP[2][9] = 1;

		for (int i = 3; i <= N; i++) {
			for (int j = 0; j <= 9; j++) {
				if (j == 0) {
					DP[i][j] = DP[i-1][j + 1];
				}
				else if (j == 9) {
					DP[i][j] = DP[i-1][j - 1];
				}
				else {
					DP[i][j] = (DP[i - 1][j - 1] + DP[i-1][j+1]) % 1000000000;

				}
			}

		}
		long long result = 0;
		for (int i = 0; i <= 9; i++) {
			result = (DP[N][i] + result) % 1000000000;
		}
		cout << result;
	}


}