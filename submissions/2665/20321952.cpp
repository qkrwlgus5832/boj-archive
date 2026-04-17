#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>


using namespace std;

int graph[51][51];

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int DP[51][51][4];
int n;

void recursion(int i, int j, char direction, bool check[51][51]) {
	if (i == n - 1 && j == n - 1) {
		DP[n - 1][n - 1][direction] = 0;
		return;
	}
	for (int i1 = 0; i1 < 4; i1++) {
		int ni = i + dir[i1][0];
		int nj = j + dir[i1][1];

		if (ni < 0 || nj < 0 || ni >= n || nj >= n)
			continue;

		if (check[ni][nj] == true)
			continue;

		if (DP[ni][nj][i1] == -1) {
			check[ni][nj] = true;
			recursion(ni, nj,i1, check);
			check[ni][nj] = false;
		}
		
		if (DP[i][j][direction] == -1) {
			DP[i][j][direction] = DP[ni][nj][i1];
		}
		else {
			DP[i][j][direction] = min(DP[i][j][direction], DP[ni][nj][i1]);
		}
	}

	if (graph[i][j] == 0) {
		DP[i][j][direction]++;
	}

}


int main() {

	cin >> n;
	vector <pair <int, int>> black;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &graph[i][j]);
			if (graph[i][j] == 0) {
				black.push_back({ i,j });
			}
		}
	}
	
	memset(DP, -1, sizeof(DP));
	bool check[51][51] = { false, };
	check[0][0] = true;
	recursion(0, 0, 0, check);
	int result = INT_MAX;
	for (int i = 0; i < 4; i++) {
		if (DP[0][0][i] == -1)
			continue;
		result = min(result, DP[0][0][i]);
	}
	cout << result;

	//system("Pause");
}
