#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int dir[4][2] = { {-1,0}, {1,0}, {0,1}, {0, -1} };

int R, C, M;

int result = 0;


class shark_ {
public:
	int speed; int direction;  int size;
	
	shark_( int speed, int direction, int size) {
		 this->speed = speed; this->direction = direction; this->size = size;
	}
};

vector <pair <shark_ ,pair <int , int >>> shark;

vector <shark_> map[101][101];

void sharkmove(int i, int j, shark_ &movingshark) {
	queue <pair <int, int>> q;

	int distance = movingshark.speed;
	int direction = movingshark.direction;
	int size = movingshark.size;

	
	int count = 0;

	if (direction < 2) {
		int s = distance % ((R - 1) * 2);
		int ni = i;
		while (s--) {
			if (ni == 0 && direction == 0) { movingshark.direction = 1; direction = 1; };
			if (ni == R - 1 && direction == 1) {
				movingshark.direction = 0;  direction = 0;
			}
			ni += dir[direction][0];
		}
		if (map[ni][j].size() == 1) {
			if (map[ni][j][0].size < size)
				map[ni][j][0] = movingshark;
		}
		else {
			movingshark.direction = direction;
			map[ni][j].push_back(movingshark);
		}
	}
	else {
		int s = distance % ((C - 1) * 2);
		int nj = j;
		while (s--) {
			if (nj == 0 && direction == 3) { movingshark.direction = 2; direction = 2; }
			if (nj == C - 1 && direction == 2) {
				movingshark.direction = 3;  direction = 3;
			}
			nj += dir[direction][1];
		}
		if (map[i][nj].size() == 1) {
			if (map[i][nj][0].size < size)
				map[i][nj][0] = movingshark;
		}
		else {
			movingshark.direction = direction;
			map[i][nj].push_back(movingshark);
		}
	}



}


void fishing(int fishingcount) {

	for (int i = 0; i < R; i++) {
		if (map[i][fishingcount].size() == 1) {
			result += map[i][fishingcount][0].size;
			map[i][fishingcount].erase(map[i][fishingcount].begin());
			return;
		}
	}
}

void clear() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j].size() == 1) {
				shark.push_back(make_pair(map[i][j][0], make_pair(i, j)));
				map[i][j].clear();
			}
		}
	}
}

void shaks() {
	for (int i = 0; i < shark.size(); i++) {
		sharkmove(shark[i].second.first, shark[i].second.second, shark[i].first);
	}
}
int main() {

	R = 100;
	C = 100;
	M = 100;
	cin >> R >> C >> M;
	int r, c, s, d, z;



	for (int j = 0; j < M; j++) {
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		shark_ tmp = shark_( s, d - 1, z);
		map[r - 1][c - 1].push_back(tmp);

	}

	

	for (int fishingcount = 0; fishingcount < C; fishingcount++) {

		fishing(fishingcount);

		shark.clear();

		clear();

		shaks();

	
	}

	cout << result;
	//system("Pause");
	
}