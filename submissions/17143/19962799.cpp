#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int R, C, M;


class shark {
public:
	int x;
	int y;
	int s;
	int d;
	int z;
	shark(int x, int y, int s, int d, int z) {
		this->x = x;
		this->y = y;
		this->s = s;
		this->d = d;
		this->z = z;
	}
};

vector <shark> v;

pair <int, int> graph[101][101];
int dir[4][2] = { {-1, 0} , {1,0}, {0,1}, {0,-1} };
bool check[10001];

void updateSpeed() {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].d == 0 || v[i].d == 1) {
			v[i].s = v[i].s % ((R - 1) * 2);
		}
		else if (v[i].d == 2 || v[i].d == 3) {
			v[i].s = v[i].s % ((C - 1) * 2);
		}
	}
}

pair <int, int> getlocation(int x, int y, int dir) {
	if (dir == 0) {
		return make_pair(0, y);
	}
	else if (dir == 1) {
		return make_pair(R - 1, y);

	}
	else if (dir == 2) {
		return make_pair(x, C - 1);
	}
	return make_pair(x, 0);

}
void moveShark() {
	for (int i = 0; i < v.size(); i++) {
		if (check[i] == false) {
			graph[v[i].x][v[i].y] = make_pair(0,0);
			
			int tmps = v[i].s;

			while (tmps > 0) {

				int count;

				if (v[i].d == 0) {
					count = v[i].x;
				}
				else if (v[i].d == 1) {
					count = R - 1 - v[i].x;
				}
				else if (v[i].d == 2) {
					count = C - 1 - v[i].y;
				} 
				else {
					count = v[i].y;
				}
				if (count >= tmps) {
					v[i].x += dir[v[i].d][0] * tmps;
					v[i].y += dir[v[i].d][1] * tmps;
					tmps -= tmps;
				}
				else {
					tmps -= count;
					pair <int, int> location = getlocation(v[i].x, v[i].y, v[i].d);
					v[i].x = location.first; v[i].y = location.second;
					if (v[i].d == 0 || v[i].d == 2) {
						v[i].d++;
					}
					else {
						v[i].d--;
					}
				}
			}

		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (check[i] == true)
			continue;
		if (graph[v[i].x][v[i].y].second > 0) {
			if (v[i].z > graph[v[i].x][v[i].y].second) {
				check[graph[v[i].x][v[i].y].first] = true;
				graph[v[i].x][v[i].y].first = i;
				graph[v[i].x][v[i].y].second = v[i].z;
			}
			else {
				check[i] = true;
			}
		
		}
		else {
			graph[v[i].x][v[i].y].first = i;
			graph[v[i].x][v[i].y].second = v[i].z;
		}
	}
}
int main() {
	cin >> R >> C >> M;
	
	int r, c, s, d, z;

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		v.push_back(shark(r - 1, c - 1, s, d - 1, z));
		graph[r - 1][c - 1] = make_pair(i,z);
	}
	updateSpeed();
	int result = 0;
	for (int j = 0; j < C; j++) {
		for (int i = 0; i < R; i++) {
			if (graph[i][j].second > 0) {
				result += graph[i][j].second;
				check[graph[i][j].first] = true;
				graph[i][j] = make_pair(0, 0);
				break;
			}
		}
		moveShark();

	}
	cout << result;
	//system("Pause");
}