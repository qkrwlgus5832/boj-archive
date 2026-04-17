#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int score[1000];
int DP[1000][1000];


void dpdp() {
	for (int i = 2; i < N; i++) {
		DP[1][i] = max(DP[1][i - 2], DP[2][i - 2]) + score[i];
		DP[2][i] = DP[1][i - 1] + score[i];

	}
}



int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> score[i];
	}

	DP[1][0] = score[0];
	DP[2][0] = score[0];

	DP[1][1] = score[1];
	DP[2][1] = score[0] + score[1];

	dpdp();
	cout << max(DP[1][N - 1], DP[2][N - 1]);
}
