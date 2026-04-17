#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>

using namespace std;


int R, C;

char gaspipe[26][26];

bool check[26][26][2];

pair <int, int> start;

pair <int, int> end_;


int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, {0, 1} };

int result = 0;

int checkpipe(int i, int j, int direction) {
	if (gaspipe[i][j] == '+')
		return direction;
	else if (gaspipe[i][j] == '|') {
		if (direction == 0 || direction == 1)
			return direction;
		else
			return -1;
	}
	else if (gaspipe[i][j] == '-') {
		if (direction == 2 || direction == 3)
			return direction;
		else
			return -1;
	}
	else if (gaspipe[i][j] == '1') {
		if (direction == 0)
			return 3;
		else if (direction == 2)
			return 1;
		else
			return -1;
	}
	else if (gaspipe[i][j] == '2') {
		if (direction == 1)
			return 3;
		else if (direction == 2)
			return 0;
		else
			return -1;
	}
	else if (gaspipe[i][j] == '3') {
		if (direction == 1)
			return 2;
		else if (direction == 3)
			return 0;
		else
			return -1;
	}
	else if (gaspipe[i][j] == '4') {
		if (direction == 3)
			return 1;
		else if (direction == 0)
			return 2;
		else
			return -1;
	}

	return -1;


}


void DFS(int i ,int j, int direction) {
	if (direction == -1) {
		for (int i1 = 0; i1 < 4; i1++) {
			int ni = i + dir[i1][0];
			int nj = j + dir[i1][1];
			if (ni < 0 || nj < 0 || ni >= R || nj >= C)
				continue;
			if (gaspipe[ni][nj] != '.') {
				DFS(ni, nj, i1);
				
			}

		}
	}
	else if (i == end_.first && j == end_.second) {
		result = 1;
		return;
	}
	else {
		check[i][j][direction/2] = true;

		direction = checkpipe(i, j , direction);
		if (direction == -1)
			return;
		DFS(i + dir[direction][0], j + dir[direction][1] , direction);
	}
}

bool checkIfallpipeinGas() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (gaspipe[i][j] == '+') {
				if (!(check[i][j][0] && check[i][j][1]))
					return false;
			}
			else if (gaspipe[i][j] != '.' && gaspipe[i][j] != 'M' && gaspipe[i][j] != 'Z') {
				if (!(check[i][j][0] || check[i][j][1]))
					return false;
			}
		}
	}
	return true;
}
bool checkIfGasCanGo(int i, int j) {
	memset(check, false, sizeof(check));
	gaspipe[i][j] = '|';
	DFS(start.first, start.second, -1);
	if (result == 1  && checkIfallpipeinGas()) {
		
		cout << i + 1 << " " << j + 1 << " " << gaspipe[i][j];
		return true;
		
	}
	memset(check, false, sizeof(check));

	gaspipe[i][j] = '-';
	DFS(start.first, start.second, -1);
	if (result == 1 && checkIfallpipeinGas()) {
	
		cout << i + 1 << " " << j + 1 << " " << gaspipe[i][j];
		return true;
	
	}
	memset(check, false, sizeof(check));

	gaspipe[i][j] = '+';

	DFS(start.first, start.second, -1);
	if (result == 1 && checkIfallpipeinGas()) {
		cout << i + 1 << " " << j + 1 << " " << gaspipe[i][j];
		return true;
	}
	for (int i1 = 1; i1 <= 4; i1++) {
		memset(check, false, sizeof(check));
		gaspipe[i][j] = '0' + i1;
		DFS(start.first, start.second, -1);
		if (result == 1 && checkIfallpipeinGas()) {
			cout << i + 1 << " " << j + 1 << " " << gaspipe[i][j];
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> gaspipe[i][j];
			if (gaspipe[i][j] == 'M') {
				start.first = i; start.second = j;
			}
			else if (gaspipe[i][j] == 'Z') {
				end_.first = i; end_.second = j;
			}
		}
	}

	int f = 0;
	//checkIfGasCanGo(1, 1);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (gaspipe[i][j] == '.') {
				if (checkIfGasCanGo(i, j)) {
					f = 1;
					break;
				}
				gaspipe[i][j] = '.';
			}
		}
		if (f == 1)
			break;
	}
	//system("Pause");
}