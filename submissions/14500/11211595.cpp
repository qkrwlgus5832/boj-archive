#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int graph[501][501];
bool check2[501][501];
int N, M;

int result = 0;
void recursion(int x, int y, int count, int dd) {

	if (x < 0 || y < 0 || x >= N || y >= M)
		return;
	else if (count == 3) {
		dd = dd + graph[x][y];
		result = max(result, dd);
		return;
	}
	check2[x][y] = true;
	if (check2[x + 1][y] == false) {

		recursion(x + 1, y, count + 1, dd + graph[x][y]);

		check2[x+1][y] = false;
	}
	if (check2[x - 1][y] == false) {
	
		recursion(x - 1, y, count + 1, dd + graph[x][y]);
		check2[x - 1][y] = false;
	}
	if (check2[x][y + 1] == false) {

		recursion(x, y + 1, count + 1, dd + graph[x][y]);
		check2[x][y + 1] = false;
	}
	if (check2[x][y - 1] == false) {
	
		recursion(x, y - 1, count + 1, dd + graph[x][y]);
		check2[x][y - 1] = false;
	}





}

int check(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M)
		return 0;
	else
		return 1;
}



void fuck(int x, int y) {
	int dd = 0;
	if (check(x, y) == 1)
		dd = dd + graph[x][y];
	else
		return;
	if (check(x, y + 1) == 1)
		dd = dd + graph[x][y + 1];
	else
		return;
	if (check(x, y + 2) == 1)
		dd = dd + graph[x][y + 2];
	else
		return;
	if (check(x + 1, y + 1) == 1)
		dd = dd + graph[x + 1][y + 1];
	else
		return;

	result = max(dd, result);

}
void fuck1(int x, int y) {
	int dd = 0;
	if (check(x, y) == 1)
		dd = dd + graph[x][y];
	else
		return;
	if (check(x+1, y) == 1)
		dd = dd + graph[x+1][y];
	else
		return;
	if (check(x+2, y) == 1)
		dd = dd + graph[x+2][y];
	else
		return;
	if (check(x + 1, y + 1) == 1)
		dd = dd + graph[x + 1][y + 1];
	else
		return;

	result = max(dd, result);

}

void fuck2(int x, int y) {
	int dd = 0;
	if (check(x+1, y) == 1)
		dd = dd + graph[x+1][y];
	else
		return;
	if (check(x, y + 1) == 1)
		dd = dd + graph[x][y + 1];
	else
		return;
	if (check(x+1, y + 1) == 1)
		dd = dd + graph[x+1][y + 1];
	else
		return;
	if (check(x + 1, y + 2) == 1)
		dd = dd + graph[x + 1][y + 2];
	else
		return;

	result = max(dd, result);

}

void fuck3(int x, int y) {
	int dd = 0;
	if (check(x+1, y) == 1)
		dd = dd + graph[x+1][y];
	else
		return;
	if (check(x, y + 1) == 1)
		dd = dd + graph[x][y + 1];
	else
		return;
	if (check(x+1, y + 1) == 1)
		dd = dd + graph[x+1][y + 1];
	else
		return;
	if (check(x + 2, y + 1) == 1)
		dd = dd + graph[x + 2][y + 1];
	else
		return;

	result = max(dd, result);

}

int main() {
	
	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
		}
	}






	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			recursion(i, j, 0 , 0);
			fuck(i, j);
			fuck1(i, j);
			fuck2(i, j);
			fuck3(i, j);
		}
	}

	cout << result;

}