#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N;

char graph[51][51];



int check(int i, int j, char direction)
{
	int dirx, diry = 0;
	if (direction == 'u') {
		dirx = -1; diry = 0;
	}
	else if (direction == 'd') {
		dirx = 1; diry = 0;
	}
	else if (direction == 'l') {
		dirx = 0; diry = -1;
	}
	else if (direction == 'r') {
		dirx = 0; diry = 1;
	}
	int count = 1;
	for (int i1 = 1; i1 <= N; i1++) {
		int nx = i + i1 * dirx;
		int ny = j + i1 * diry;
		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			break;
		if (graph[i][j] == graph[nx][ny]) {
			count++;
		}
		else
			break;
	}

	return count;
}

int maxvalue(int i, int j) {
	int result = 0;
	result = max(check(i, j, 'u') + check(i, j , 'd') - 1, result);
	result = max(check(i, j, 'l') + check(i, j, 'r') - 1, result);
	return result;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i + 1 < N) {
				swap(graph[i][j], graph[i + 1][j]);
				result = max(result, maxvalue(i, j));
				result = max(result, maxvalue(i + 1, j));
				swap(graph[i][j], graph[i + 1][j]);
			}
			if (j + 1 < N) {
				swap(graph[i][j], graph[i][j + 1]);
				result = max(result, maxvalue(i, j));
				result = max(result, maxvalue(i , j + 1));	
				swap(graph[i][j], graph[i][j + 1]);
			}

		}
	}
	cout << result;
}