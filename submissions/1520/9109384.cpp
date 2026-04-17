#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


int N;
int M;
int arr[501][501];
int DP[501][501];
int main() {


	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	DP[0][0] = 1;
	for (int i = 0; i < M; i++) {


		for (int j = 0; j < N; j++) {
			if (j + 1 <= N - 1 && arr[i][j + 1] < arr[i][j]) {
				DP[i][j + 1] = DP[i][j + 1] + DP[i][j];

			}
		
		}

		for (int j = 0; j < N; j++) {
			if (j - 1 <= N - 1 && arr[i][j - 1] < arr[i][j]) {
				DP[i][j - 1] = DP[i][j - 1] + DP[i][j];

			}

		}




		for (int j = 0; j < N; j++) {
			if (i - 1 >= 0 && arr[i - 1][j] < arr[i][j]) {
				DP[i - 1][j] = DP[i - 1][j] + DP[i][j];
			}


		}
		for (int j = 0; j < N; j++) {
			if (i + 1 <= M - 1 && arr[i + 1][j] < arr[i][j]) {
				DP[i + 1][j] = DP[i + 1][j] + DP[i][j];

			}
		}

		
	
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}
}