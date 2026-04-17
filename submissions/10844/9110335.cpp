#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

long long DP[101][10];
int N;
int main() {
	cin >> N;
		DP[1][0] = 1;
		DP[1][1] = 1;
		DP[1][2] = 1;
		DP[1][3] = 1;

		DP[1][4] = 1;

		DP[1][5] = 1;

		DP[1][6] = 1;

		DP[1][7] = 1;

		DP[1][8] = 1;

		DP[1][9] = 1;

		for (int i = 2; i <= N; i++) {
			for (int j = 0; j <= 9; j++) {
				if (j == 0) {
					DP[i][j] = DP[i - 1][j + 1];
				}
				else if (j == 9) {
					DP[i][j] = DP[i - 1][j - 1];
				}
				else {
					DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;

				}
			}

		}
		
		long long result = 0;
		for (int i = 1; i <= 9; i++) {
			result = (DP[N][i] + result) % 1000000000;
		}
		cout << result;
	
	


}