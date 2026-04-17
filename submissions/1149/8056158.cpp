#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int arr[2000][3];
int dp[2000][3];



int main() {
	int N;
	cin >> N;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}



	int sum1 = 0;

	dp[0][0] = 26;
	dp[0][1] = 40;
	dp[0][2] = 83;




	for (int i = 1; i < N; i++) {
	
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];

		
	}

	int min2 = min(dp[N - 1][0], dp[N - 1][1]);
	cout << min(min2,dp[N-1][2]);
}