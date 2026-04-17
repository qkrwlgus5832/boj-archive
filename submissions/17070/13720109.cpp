#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>


using namespace std;

int N;
int result = 0;

int house[17][17];
bool check[17][17];


bool isblank(int direction, int i, int j) {
	if (direction == 0) {
		j = j + 1;
		if (j >= N || house[i][j] == 1)
			return false;
		else
			return true;
	}
	else if (direction == 1) {
		i = i + 1;
		if (i >= N || house[i][j] == 1)
			return false;
		else
			return true;
	}
	else if (direction == 2) {
		i = i + 1; j = j + 1;
		if (j >= N || i >= N || house[i][j] == 1 || house[i-1][j] == 1 || house[i][j-1] == 1)
			return false;
		else
			return true;
	}
}
void recursion(int direction, int i, int j) {
	if (i == N - 1 && j == N - 1) {
		result++;
		return;
	}
	if (direction == 0) {
		if (isblank(0, i, j) == true)
			recursion(0, i, j + 1);
		if (isblank(2, i, j) == true)
			recursion(2, i + 1, j + 1);
	}
	else if (direction == 1) {
		if (isblank(1, i, j) == true)
			recursion(1, i + 1, j);
		if (isblank(2, i, j) == true)
			recursion(2, i + 1, j + 1);
	}
	else if (direction == 2) {
		if (isblank(0, i, j) == true)
			recursion(0, i, j + 1);
		if (isblank(1, i, j) == true)
			recursion(1, i + 1, j);
		if (isblank(2, i, j) == true)
			recursion(2, i + 1, j + 1);
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &house[i][j]);
		}
	}

	check[0][0] = true;
	check[0][1] = true;

	recursion(0, 0, 1);

	cout << result;
	//system("Pause");
}