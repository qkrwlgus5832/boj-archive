#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>


using namespace std;

int N;

long long pipe[33][33][3];

int house[33][33];

bool isblank(int i, int j, int pipe) {
	if (pipe == 0) {
		if (house[i][j + 1] == 0)
			return true;
	}
	else if (pipe == 1) {
		if (house[i + 1][j] == 0)
			return true;
	}
	else if (pipe == 2) {
		if (house[i + 1][j] == 0 && house[i][j + 1] == 0 && house[i + 1][j + 1] == 0)
			return true;
	}
	return false;
}
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &house[i][j]);
		}
	}

	pipe[0][1][0] = 1;

	for (int i = 0; i < N; i++) {
		int j;
		if (i == 0)
			j = 2;
		else
			j = 0;
		for ( j = 0; j < N; j++) {
			if (house[i][j] == 1)
				continue;
			if (i + 1 < N && j + 1 < N && isblank(i,j, 2)) {
				pipe[i + 1][j+1][2] += pipe[i][j][0]; 
				pipe[i + 1][j+1][2] += pipe[i][j][1];
				pipe[i + 1][j + 1][2] += pipe[i][j][2];
			}
			if (j + 1 < N && isblank(i,j,0)) {
				pipe[i][j + 1][0] += pipe[i][j][0];
				pipe[i][j + 1][0] += pipe[i][j][2];
			}
			if (i + 1 < N && isblank(i,j,1)) {
				pipe[i + 1][j][1] += pipe[i][j][1];
				pipe[i + 1][j][1] += pipe[i][j][2];
			}
			
		}
	}

	cout << pipe[N - 1][N - 1][0] + pipe[N - 1][N - 1][1] + pipe[N - 1][N - 1][2];

	//system("Pause");
}