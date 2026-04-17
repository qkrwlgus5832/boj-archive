#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int number[10][13][2] = {
	{{0,0},{0,1},{0,2},{1,0},{1,2},{2,0},{2,2},{3,0},{3,2},{4,0},{4,1},{4,2}},
	{{0,0},{1,0},{2,0},{3,0},{4,0}},
	{{0,0},{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{3,0},{4,0},{4,1},{4,2}},
	{{0,0}, {0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{3,2},{4,2},{4,1},{4,0}},
	{{0,0},{1,0},{2,0},{2,1},{2,2},{1,2},{0,2},{3,2},{4,2}},
	{{0,0}, {0,1},{0,2},{1,0},{2,0},{2,1},{2,2},{3,2},{4,2},{4,1},{4,0}},
	{{0,0},{0,1},{0,2},{1,0},{2,0},{2,1},{2,2},{3,0},{4,0},{3,2},{4,2},{4,1}},
	{{0,0},{0,1},{0,2},{1,2},{2,2},{3,2},{4,2}},
	{{0,0}, {0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{3,2},{4,2},{4,1},{4,0}, {1,0}, {3,0}},
	{{0,0}, {0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{3,2},{4,2},{4,1},{4,0}, {1,0}}
};

int graph[5][20001];
int N;
bool check_[5][20001];

bool check(int i, int j, int n) {
	for (int i1 = 0; i1 < 13; i1++) {
		int ni = i + number[n][i1][0];
		int nj = j + number[n][i1][1];

		if (ni < 0 || ni >= 5 || nj < 0 || nj >= N/5) {
			return false;
		}
		if (graph[ni][nj] == '.')
			return false;

		check_[ni][nj] = true;
	}
	return true;
}


int checkNumber(int i, int j) {
	for (int n = 9; n >=0; n--) {
		if (check(i, j, n)) {
			if (n == 9) {
				if (check(i, j, 8))
					return 8;
				return 9;
			}
			return n;
		}
	}
	return -1;
}

int main() {

	cin >> N;

	char tmp;

	scanf("%c", &tmp);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < N/5; j++) {
			scanf("%c", &tmp);
			graph[i][j] = tmp;
		}
	}
	string result = "";

	for (int j = 0; j < N / 5; j++) {
		if (graph[0][j] == '#' && check_[0][j] == false) {
			int number = checkNumber(0, j);
			if (number != 1) {
				result += '0' + checkNumber(0, j);
			}
		}
	}

	cout << result;
	//system("Pause");
}
