#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

int N;
int graph[101][101];
bool check[101][101];
int x, y, d, g;
int dir[4] = { 1,2,3,0 };
void bfs(int x, int y, int d, int g) {
	int nx, ny;
	deque <int> q;
	int tg = 0;
	check[y][x] = true;
	q.push_back(d);
	if (d == 0) {
		nx = x + 1;
		ny = y;
	}
	else if (d == 1) {
		nx = x;
		ny = y - 1;
	}
	else if (d == 2) {
		nx = x - 1;
		ny = y;
	}
	else if (d == 3) {
		nx = x;
		ny = y + 1;
	}
	check[ny][nx] = true;
	int prevx = nx;
	int prevy = ny;

	while (!q.empty()) {
		if (tg == g)
			return;

		int a = q.size();
		for (int i = a-1; i >= 0; i--) {
			d = q.at(i);
			int nx, ny;

			if (dir[d] == 0) {
				nx = prevx + 1;
				ny = prevy;
				q.push_back(0);
			}
			else if (dir[d] == 1) {
				nx = prevx;
				ny = prevy - 1;
				q.push_back(1);
			}
			else if (dir[d] == 2) {
				nx = prevx - 1;
				ny = prevy;
				q.push_back(2);
			}
			else if (dir[d] == 3) {
				nx = prevx;
				ny = prevy + 1;
				q.push_back(3);
			}
			check[ny][nx] = true;
			prevx = nx;
			prevy = ny;

		}
		tg++;
	}

}


int main() {
		cin >> N;


		int result = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d %d", &x, &y, &d, &g);
			bfs(x, y, d, g);

		

		}


		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				if (check[i][j] == true) {
					if (i + 1 <= 100 && check[i + 1][j] == true)
						if (j + 1 <= 100 && check[i][j + 1] == true) {
							if (check[i + 1][j + 1] == true)
								result++;
						}
				}
			}

		}
		cout << result;

}