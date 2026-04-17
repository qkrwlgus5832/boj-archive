#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int N, M;

int paper[5][5];


int visited[5][5];

bool check[5][5] = { false, };

int result = 0;

int valueupdate(int value , int tmpi, int tmpj) {
	value *= 10;
	value += paper[tmpi][tmpj];
	check[tmpi][tmpj] = true;
	return value;
}

int calculate(int tmpi, int tmpj, char direction) {
	int value = paper[tmpi][tmpj];
	check[tmpi][tmpj] = true;
	if (direction == 1) {
		for (int i = 1; i < N; i++) {
			if (tmpi + i >= N)
				break;
			if (visited[tmpi + i][tmpj] != 1)
				break;
			else if (check[tmpi + i][tmpj] == false) {
				value = valueupdate(value, tmpi + i, tmpj);
		
			}
		}
	}
	else if (direction == 2) {
		for (int j = 1; j <= M; j++) {
			if (tmpj + j >= M)
				break;
			if (visited[tmpi][tmpj + j] != 2 )
				break;
			else if (check[tmpi][tmpj + j] == false) {
				value = valueupdate(value, tmpi, tmpj + j);
			}
		}
	}

	return value;
}


void recursion() {
	int tmpi, tmpj;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0) {
				tmpi = i;
				tmpj = j;
				flag = true;
				break;
			}
		}
		if (flag == true)
			break;
	}
	if (flag == true) {
		visited[tmpi][tmpj] = 1;
		recursion();
		visited[tmpi][tmpj] = 2;
		recursion();
		visited[tmpi][tmpj] = 0;
	}
	else {
		memset(check, false, sizeof(check));
		int tmpvalue = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (check[i][j] == false)
					tmpvalue += calculate(i, j, visited[i][j]);
			}
		}
		result = max(result, tmpvalue);
	}

}
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &paper[i][j]);
		}
	}


	recursion();
	cout << result;
	//system("Pause");
}
