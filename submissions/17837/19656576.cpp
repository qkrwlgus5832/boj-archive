#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int chess[13][13];
int dir[4][2] = { {0,1}, {0,-1},{-1, 0}, {1,0} };

vector <int> horseChess[13][13];
int N, K;

class horse {
public:
	int x;
	int y;
	int direction;
	horse(int x, int y, int direction) {
		this->x = x;
		this->y = y;
		this->direction = direction;
	}
};
vector <horse> horses;

void goingByColor(int color, int currenti, int currentj, int ni, int nj, int currentindex) {
	int count = 0;
	if (color == 0) {
		bool flag = false;

		for (int i1 = 0; i1 < horseChess[currenti][currentj].size(); i1++) {
			if (currentindex == horseChess[currenti][currentj][i1]) {
				flag = true;
			}
			if (flag == true) {
				horseChess[ni][nj].push_back(horseChess[currenti][currentj][i1]);
				horses[horseChess[currenti][currentj][i1]].x = ni;
				horses[horseChess[currenti][currentj][i1]].y = nj;
				count++;
			}
		
		}
		
	}
	else if (color == 1) {
		for (int i1 = horseChess[currenti][currentj].size() - 1; i1 >= 0; i1--) {
			horseChess[ni][nj].push_back(horseChess[currenti][currentj][i1]);
			horses[horseChess[currenti][currentj][i1]].x = ni;
			horses[horseChess[currenti][currentj][i1]].y = nj;
			count++;
			if (currentindex == horseChess[currenti][currentj][i1]) {
				break;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		horseChess[currenti][currentj].pop_back();
	}
}

int getColor(int ni, int nj) {
	int color;
	if (ni < 0 || nj < 0 || ni >= N || nj >= N) {
		color = 2;
	}
	else {
		color = chess[ni][nj];
	}
	return color;
}

bool checkIfAnswer() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (horseChess[i][j].size() >= 4) {
				return true;
			}
		}
	}
	return false;
}
bool runningTurn() {
	for (int i = 0; i < horses.size(); i++) {
		int currenti = horses[i].x;
		int currentj = horses[i].y;

		int ni = currenti+ dir[horses[i].direction][0];
		int nj = currentj + dir[horses[i].direction][1];

		int color = getColor(ni, nj);

		if (color == 2) {
			int direction = horses[i].direction;
			if (direction == 0 || direction == 2) {
				direction += 1;
			}
			else {
				direction -= 1;
			}
			horses[i].direction = direction;
			int ni = currenti + dir[horses[i].direction][0];
			int nj = currentj + dir[horses[i].direction][1];
			int color = getColor(ni, nj);
			if (color != 2) {
				goingByColor(color, currenti, currentj, ni, nj, i);
			}
			
		}
		else {
			goingByColor(color, currenti, currentj, ni, nj, i);
		}
		if (checkIfAnswer())
			return true;
	}
	
	return false;
}
int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &chess[i][j]);
		}
	}
	int x, y, direction;
	for (int i = 0; i < K; i++) {
		cin >> x >> y >> direction;
		horses.push_back(horse(--x, --y, --direction));
		horseChess[x][y].push_back(i);
	}

	for (int i = 0; i < 1000; i++) {
		
		if (runningTurn()) {
			cout << i + 1;
			return 0;
		}
	}
	cout << -1;

}