#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>
using namespace std;

int N, L;


int graph[101][101];
bool check[101][101];

int result = 0;

int dir[4][2] = { { 0 ,-1 }, {0,1},{-1,0},{1,0} };

bool recursion(int i, int j, int height, int count, int direction) {
	if (count == L) {
		return true;
	}
	if (i < 0 || j < 0 || i >= N || j >= N)
		return false;

	if (check[i][j] == false && graph[i][j] == height) {
		check[i][j] = true;
		return recursion(i + dir[direction][0], j + dir[direction][1], height, count + 1, direction);
	}
	else {
		return false;
	}

}
void rowcheck() {
	for (int i = 0; i < N; i++) {
		bool flag = false;
		bool isAnswer = true;
		for (int j = 0; j < N - 1; j++) {
			if (graph[i][j] != graph[i][j + 1]) {
				if (graph[i][j] < graph[i][j + 1]) {
					isAnswer = isAnswer &&  recursion(i, j, graph[i][j], 0, 0);
				}
				else {
					isAnswer = isAnswer && recursion(i, j + 1, graph[i][j + 1], 0, 1);
				}
				flag = true;
			}
		}
		if (flag == false)
			result++;
		else if (isAnswer)
			result++;
	}
}

void colcheck() {
	for (int j = 0; j < N ; j++) {
		bool flag = false;
		bool isAnswer = true;
		for (int i = 0; i < N - 1; i++) {
			if (graph[i][j] != graph[i+ 1][j]) {
				if (graph[i][j] < graph[i + 1][j]) {
					isAnswer = isAnswer && recursion(i, j, graph[i][j], 0, 2);
				}
				else {
					isAnswer = isAnswer && recursion(i+1 , j, graph[i + 1][j], 0, 3);
				}
				flag = true;
			}
		}
		if (flag == false)
			result++;
		else if (isAnswer)
			result++;
	}
}
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	rowcheck();
	memset(check, false, sizeof(check));
	colcheck();
	cout << result;
	//system("Pause");
}