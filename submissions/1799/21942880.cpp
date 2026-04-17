#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int graph[11][11];
int N;
int result = 0;


int checkDiagonal1[121];
int checkDiagonal2[121];

int diagonal1[11][11];
int diagonal2[11][11];


vector <pair <int, int>> v;


void checkMinus(int i, int j) {
	int dir[4][2] = { { -1,-1 }, { 1, 1 }, { -1, 1 }, { 1, -1 } };

	for (int i1 = 0; i1 < 2; i1++) {
		int ni = i + dir[i1][0];
		int nj = j + dir[i1][1];


		if (ni < 0 || nj < 0 || ni >= N || nj >= N)
			continue;
		else {
			checkDiagonal1[diagonal1[ni][nj]]--;
			break;
		}
	}

	for (int i1 = 2; i1 < 4; i1++) {
		int ni = i + dir[i1][0];
		int nj = j + dir[i1][1];


		if (ni < 0 || nj < 0 || ni >= N || nj >= N)
			continue;
		else {
			checkDiagonal2[diagonal2[ni][nj]]--;
			break;
		}
	}

}

void checkPlus(int i, int j) {
	int dir[4][2] = { { -1,-1 }, { 1, 1 }, { -1, 1 }, { 1, -1 } };
	for (int i1 = 0; i1 < 2; i1++) {
		int ni = i + dir[i1][0];
		int nj = j + dir[i1][1];


		if (ni < 0 || nj < 0 || ni >= N || nj >= N)
			continue;
		else {
			checkDiagonal1[diagonal1[ni][nj]]++;
			break;
		}
	}

	for (int i1 = 2; i1 < 4; i1++) {
		int ni = i + dir[i1][0];
		int nj = j + dir[i1][1];


		if (ni < 0 || nj < 0 || ni >= N || nj >= N)
			continue;
		else {
			checkDiagonal2[diagonal2[ni][nj]]++;
			break;
		}
	}
}



void recursion(int depth, int index) {

	for (int i1 = index; i1 < v.size(); i1++) {
		int i = v[i1].first;
		int j = v[i1].second;

		if (graph[i][j] == 1 && checkDiagonal1[diagonal1[i][j]] >= 0 && checkDiagonal2[diagonal2[i][j]] >= 0) {
			graph[i][j] = 0;
			checkMinus(i, j);
			recursion(depth + 1, i1 + 1);
			graph[i][j] = 1;
			checkPlus(i, j);
		}

	}

	result = max(result, depth);

}


void initDiagonalCount(int i, int j, int count, pair <int, int> direction, int diagonal[11][11]) {
	int ni = i;
	int nj = j;
	diagonal[ni][nj] = count;
	while (1) {
		ni += direction.first;
		nj += direction.second;

		if (ni < 0 || nj < 0 || ni >= N || nj >= N)
			break;

		diagonal[ni][nj] = count;
	}

}
int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				v.push_back({ i,j });
			}
		}
	}


	int count = 1;
	for (int i = 0; i < N; i++) {
		initDiagonalCount(i, 0, count, { 1,1 }, diagonal1);
		count++;
	}

	for (int j = 1; j < N; j++) {
		initDiagonalCount(0, j, count , { 1,1 }, diagonal1);
		count++;
	}

	count = 1;
	for (int i = 1; i < N; i++) {
		initDiagonalCount(i, N-1, count, { 1,-1 }, diagonal2);
		count++;
	}

	for (int j = 0; j < N; j++) {
		initDiagonalCount(0, j, count , { 1,-1 }, diagonal2);
		count++;
	}

	recursion(0, 0);

	cout << result;
	//system("Pause");
}
