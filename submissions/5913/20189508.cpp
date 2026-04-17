#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int check[5][5];

int dir[4][2] = { {-1,0},{1,0}, {0,-1},{0,1} };

int count_;
int result = 0;

int dfscheck[5][5][2];

class node {
public :
	int x;
	int y;
	bool name;

	node(int x, int y, bool name) {
		this->x = x;
		this->y = y;
		this->name = name;
	}
};

bool checkIfAnswer() {
	int count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (check[i][j] != -1 && dfscheck[i][j][0] > 0 || dfscheck[i][j][1] > 0)
				count++;
		}
	}
	if (count == count_)
		return true;
	return false;
}
void DFS(int x, int y, int x1,int y1, int level) {
	for (int i1 = 0; i1 < 4; i1++) {
		int ni = x + dir[i1][0];
		int nj = y + dir[i1][1];

		if (ni < 0 || nj < 0 || ni >= 5 || nj >= 5)
			continue;
		else if (check[ni][nj] == -1)
			continue;
		else if (dfscheck[ni][nj][0]  > 0 || dfscheck[ni][nj][1] > 0)
			continue;
		
		dfscheck[ni][nj][0] = level;

		for (int i2 = 0; i2 < 4; i2++) {
			int ni2 = x1 + dir[i2][0];
			int nj2 = y1 + dir[i2][1];

			if (ni2 < 0 || nj2 < 0 || ni2 >= 5 || nj2 >= 5)
				continue;
			else if (check[ni2][nj2] == -1)
				continue;

			else if (dfscheck[ni2][nj2][0] == level) {
				result += checkIfAnswer();
				continue;
			}
			else if (dfscheck[ni2][nj2][1] > 0 || dfscheck[ni2][nj2][0] > 0)
				continue;

			dfscheck[ni2][nj2][1] = level;
			DFS(ni, nj, ni2, nj2, level + 1);
			dfscheck[ni2][nj2][1] = 0;
			
		}
		dfscheck[ni][nj][0] = 0;
	}



}
int main() {
	int K;
	cin >> K;
	int a, b;

	count_ = 25 - K;

	for (int i = 0; i < K; i++) {
		scanf("%d %d", &a, &b);
		check[--a][--b] = -1;
	}
	
	dfscheck[0][0][0] = 1;
	dfscheck[4][4][1] = 1;

	DFS(0, 0, 4, 4, 2);
	cout << result;
	//system("Pause");
}