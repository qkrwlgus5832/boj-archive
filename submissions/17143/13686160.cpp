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

	if (distance == 0) {
		map[i][j].push_back(movingshark);
		return;
	}

	int count = 0;

	q.push(make_pair(i, j));

	while (!q.empty()) {
		int fronti = q.front().first;
		int frontj = q.front().second;

		fronti += dir[direction][0];
		frontj += dir[direction][1];

		if (fronti < 0 || frontj < 0 || fronti >= R || frontj >= C) {
			if (direction == 0) 
				direction = 1;
			else if (direction == 1)
				direction = 0;
			else if (direction == 2)
				direction = 3;
			else if (direction == 3)
				direction = 2;
			continue;
		}
		q.pop();
		count++;
		q.push(make_pair(fronti, frontj));


		if (count == distance) {
			if (map[fronti][frontj].size() == 1) {
				if (map[fronti][frontj][0].size < size) {
					map[fronti][frontj][0] = movingshark;
				}
			}

			else {
				movingshark.direction = direction;
				map[fronti][frontj].push_back(movingshark);
			}
		
			return;
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


int main() {

	cin >> R >> C >> M;
	int r, c, s, d, z;

	for (int j = 0; j < M; j++) {
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		shark_ tmp = shark_( s, d - 1, z);
		map[r - 1][c - 1].push_back(tmp);

	}

	

	for (int fishingcount = 0; fishingcount < C; fishingcount++) {

		fishing(fishingcount);

		//setzero();

		shark.clear();

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j].size() == 1) {
					shark.push_back(make_pair(map[i][j][0], make_pair(i,j)));
					map[i][j].clear();
				}
			}
		}
		for (int i = 0; i < shark.size(); i++)
			sharkmove(shark[i].second.first, shark[i].second.second, shark[i].first);
		
		//cout << endl;
		//for (int i = 0; i < 5; i++) {
		//	for (int j = 0; j < C; j++) {
		//		if (map[i][j].size() >= 1)
		//			cout << map[i][j][0].size << " ";
		//	/*	else
		//			cout << "0" << " ";*/
		//	}
		////	cout << endl;
		//}
		//cout << endl;
	}

	cout << result;
//	system("Pause");
	
}