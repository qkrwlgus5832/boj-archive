#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int graph[501][501];

bool check[501][501];

int result = 0;
int dir[4][2] = { {-1,0},{1,0}, {0, -1}, {0,1} };

int checkIfBound(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return -1;
	return graph[i][j];
}

int checkLeftFuck(int i, int j) {
	int value = 0;
	int tmpvalue = 0;
	tmpvalue = checkIfBound(i + 1, j - 1);
	if (tmpvalue == -1)
		return -1;
	else
		value += tmpvalue;
	
	tmpvalue = checkIfBound(i + 1, j);
	if (tmpvalue == -1)
		return -1;
	else
		value += tmpvalue;

	tmpvalue = checkIfBound(i + 2, j);
	if (tmpvalue == -1)
		return -1;
	else
		value += tmpvalue;
	return value;
}
int checkRightFuck(int i, int j) {

	int value = 0;
	int tmpvalue = 0;
	tmpvalue = checkIfBound(i + 1, j);
	if (tmpvalue == -1)
		return -1;
	else
		value += tmpvalue;

	tmpvalue = checkIfBound(i + 2, j);
	if (tmpvalue == -1)
		return -1;
	else
		value += tmpvalue;

	tmpvalue = checkIfBound(i + 1, j + 1);
	if (tmpvalue == -1)
		return -1;
	else
		value += tmpvalue;
	return value;


}
int checkDownFuck(int i, int j) {

	int value = 0;
	int tmpvalue = 0;
	tmpvalue = checkIfBound(i, j + 1);
	if (tmpvalue == -1)
		return -1;
	else
		value += tmpvalue;

	tmpvalue = checkIfBound(i, j + 2);
	if (tmpvalue == -1)
		return -1;
	else
		value += tmpvalue;

	tmpvalue = checkIfBound(i + 1, j + 1);
	if (tmpvalue == -1)
		return -1;
	else
		value += tmpvalue;
	return value;

}
int checkUpFuck(int i, int j) {

	int value = 0;
	int tmpvalue = 0;
	tmpvalue = checkIfBound(i + 1, j);
	if (tmpvalue == -1)
		return -1;
	else
		value += tmpvalue;

	tmpvalue = checkIfBound(i + 1, j - 1);
	if (tmpvalue == -1)
		return -1;
	else
		value += tmpvalue;

	tmpvalue = checkIfBound(i + 1, j + 1);
	if (tmpvalue == -1)
		return -1;
	else
		value += tmpvalue;
	return value;


}

void checkFuck(int i, int j) {
	vector <vector <int>> v;
	result = max(result, graph[i][j]  + checkDownFuck(i, j));
	result = max(result, graph[i][j]  +checkUpFuck(i, j));
	result = max(result, graph[i][j]  +checkRightFuck(i, j));
	result = max(result, graph[i][j] + checkLeftFuck(i, j));

}
void recursion(int i, int j, int count, int value) {
	if (count == 4) {
		result = max(result, value);
		return;
	}
	for (int i1 = 0; i1 < 4; i1++) {
		int ni = i + dir[i1][0];
		int nj = j + dir[i1][1];

		if (ni < 0 || nj < 0 || ni >= N || nj >= M)
			continue;
		if (check[ni][nj] == false) {
			check[ni][nj] = true;
			recursion(ni, nj, count + 1, value + graph[ni][nj]);
			check[ni][nj] = false;
		}
		
	}
}

int main() {
	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);

		}
	}
	vector <pair <int, int>> v;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check[i][j] = true;
			recursion(i, j, 1, graph[i][j]);
			checkFuck(i ,j);
			check[i][j] = false;
		}
	}
	cout << result;
	//system("Pause");
}