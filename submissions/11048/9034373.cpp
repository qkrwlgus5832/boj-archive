#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int M;
int Arr[1001][1001];
int DP[1001][1001];

int main() {
	cin >> N >> M;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> Arr[i][j];
		}
	}


	for (int i = N; i >= 1; i--) {
		for (int j = M; j >= 1; j--) {
			DP[i][j] = Arr[i][j];
			if (i + 1 <= N && j + 1 <= M) {
				DP[i][j] = max(DP[i + 1][j+1] + Arr[i][j], DP[i][j]);
			}
			if (i + 1 <= N) {
				DP[i][j] = max(DP[i + 1][j] + Arr[i][j] , DP[i][j]);
			}
			if (j + 1 <= M) {
				DP[i][j] = max(DP[i][j+1] + Arr[i][j], DP[i][j]);
			}
		
		}
	}

	cout << DP[1][1];
}