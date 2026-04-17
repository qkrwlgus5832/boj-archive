#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;


int N;
int M;
short arr[501][501];
int DP[501][501];


void DFS(int x, int y) {

	
		if (x - 1 >= 0 && arr[x - 1][y] < arr[x][y]) {
			DP[x][y] = DP[x][y] + 1;
			DFS(x - 1, y);
		}


		if (y - 1 >= 0 && arr[x][y - 1] < arr[x][y]) {
			DP[x][y] = DP[x][y] + 1;
			DFS(x, y - 1);

		}

		if (x + 1 <= M - 1 && arr[x + 1][y] < arr[x][y]) {
			DP[x][y] = DP[x][y] + 1;
			DFS(x + 1, y);

		}

		if (y + 1 <= N - 1 && arr[x][y + 1] < arr[x][y]) {
			DP[x][y] = DP[x][y] + 1;
			DFS(x, y + 1);

		}

}

int main() {


	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	
	DFS(0, 0);
	cout << DP[M - 2][N - 1] + DP[M-1][N-2];
}