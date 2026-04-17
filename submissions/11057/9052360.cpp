#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


int N;
long long DP[1001][1001];

int main() {
	cin >> N;

	for (int i = 0; i < 10; i++)
		DP[0][i] = 1;
	int sum = 0;
	DP[1][0] = 10;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < 10; j++) {
			DP[i][j] = DP[i][j-1] - DP[i - 1][j- 1];
			sum = (sum + DP[i][j])%10007;
		}
		sum = (sum + DP[i][0]) % 10007;
		DP[i+1][0] = sum;
		sum = 0;
	}

	cout << DP[N][0];
}