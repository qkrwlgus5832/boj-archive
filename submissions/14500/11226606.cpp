#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int graph[501][501];
bool check2[501][501];
int N, M;

int result = 0;
int dir[4][2] = { {-1,0} ,{1,0}, {0,-1}, {0,1} };
char count1[4];

void recursion(int x, int y, int count, int dd) {

	
	 if (count == 3) {

		result = max(result, dd);
	
		return;
	}
	

	for (int i = 0; i < 4; i++) {
		int x1 = x + dir[i][0];
		int y1 = y + dir[i][1];

		if (x1 < 0 || y1 < 0 || x1 >= N || y1 >= M) {
			continue;
		}

		if (check2[x1][y1] == false) {
			check2[x1][y1] = true;
			
			recursion(x1, y1, count + 1, dd + graph[x1][y1]);
			check2[x1][y1] = false;
		}
	}





}

int check(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M)
		return 0;
	else
		return 1;
}

int indexerr(int x1,int y1, int dd) {
	if (check(x1, y1) == 1)
		return dd + graph[x1][y1];
	else
		return -1;
}

void fucku(int x, int y) {
	int dd = 0;
	int x1; int y1;
	x1 = x + 1; y1 = y;

	dd=indexerr(x1, y1, dd);

	x1 = x; y1 = y + 1;
	dd=indexerr(x1, y1, dd);
	x1 = x+1; y1 = y + 1;

	dd=indexerr(x1, y1, dd);
	x1 = x + 1; y1 = y + 2;
	
	dd=indexerr(x1, y1, dd);


	result = max(dd, result);

}
void fuckd(int x, int y) {
	int dd = 0;
	int x1; int y1;
	x1 = x; y1 = y;

	dd=indexerr(x1, y1, dd);

	x1 = x; y1 = y + 1;
	dd=indexerr(x1, y1, dd);
	x1 = x; y1 = y + 2;

	dd=indexerr(x1, y1, dd);
	x1 = x + 1; y1 = y + 1;

	dd=indexerr(x1, y1, dd);


	result = max(dd, result);

}
void fuckl(int x, int y) {
	int dd = 0;
	int x1; int y1;
	x1 = x+1; y1 = y;

	dd=indexerr(x1, y1, dd);

	x1 = x; y1 = y + 1;
	dd=indexerr(x1, y1, dd);
	x1 = x+1; y1 = y + 1;

	dd=indexerr(x1, y1, dd);
	x1 = x + 2; y1 = y + 1;

	dd=indexerr(x1, y1, dd);


	result = max(dd, result);

}
void fuckr(int x, int y) {
	int dd = 0;
	int x1; int y1;
	x1 = x; y1 = y;

	dd=indexerr(x1, y1, dd);

	x1 = x+1; y1 = y;
	dd=indexerr(x1, y1, dd);
	x1 = x + 2; y1 = y;

	dd=indexerr(x1, y1, dd);
	x1 = x + 1; y1 = y + 1;

	dd=indexerr(x1, y1, dd);


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
			check2[i][j] = true;
			recursion(i, j, 0, graph[i][j]);
			check2[i][j] = false;
			fucku(i, j);
			fuckd(i, j);
			fuckl(i, j);
			fuckr(i, j);
		}
	}

	cout << result;

}