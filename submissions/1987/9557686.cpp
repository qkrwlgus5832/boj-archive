#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int R, C;
char graph[21][21];
bool check[21][21];
bool alphabet[26];
vector <int> v;
int dir[4][2] = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };




int recursion(int x, int y, int count) {
	alphabet[graph[x][y] - 65] = true;
	int nx, ny;
	int maxc = 0;
	for (int i = 0; i < 4; i++) {
		nx = x + dir[i][0];
		ny = y + dir[i][1];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
			if (alphabet[graph[nx][ny]-65] == false) {
			
				maxc= max(maxc,recursion(nx, ny, count + 1));
				
			}

		}

	}

	alphabet[graph[x][y] - 65] = false;
	
	return max(maxc, count);
}





int main() {


	cin >> R >> C;



	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> graph[i][j];
		}
	}


	

	cout << recursion(0, 0, 1);

}