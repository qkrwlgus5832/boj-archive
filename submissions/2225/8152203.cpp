#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;



int N;
int K;
int dp[202][202];

void dpdp() {

	for (int i = 3; i <= K; i++) {
		for (int j1= 0; j1 <= N; j1++) {
			for (int j = 0; j <= j1; j++) {
				if (j1 == 0)
					dp[i][j1] = 1;
				else
				dp[i][j1] = (dp[i][j1] + dp[i - 1][j]) %1000000000 ;
			}
		}

	
	}

	


}

int main() {
	

	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}

	for (int i = 0; i <= N; i++) {
		dp[2][i] = i + 1;
	}



	dpdp();

	cout << dp[K][N];
}