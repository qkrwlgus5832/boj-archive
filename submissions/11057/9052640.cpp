#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int N;
long long DP[1001][1001];

int main() {
	cin >> N;


	for (int i = 0; i < 10; i++)
		DP[0][i] = 1;
	long long sum = 0;


	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int i1 = j; i1 < 10; i1++) {
				DP[i][j] = (DP[i][j] + DP[i - 1][i1])% 10007;
			}
		}

	}
	cout << DP[N][0];
}