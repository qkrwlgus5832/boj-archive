#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
int dir[8][2] = { {-1,2} ,{ -2,1}, {-1,-2}, {-2, -1}, {1,2} ,{ 2,1},{1,-2}, {2,-1} };
bool check[301][301];
using namespace std;
int dstx, dsty;
int I;
int BFS(int x, int y) {
	queue <pair <int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;
	int level = 0;

	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int x1 = q.front().first;
			int y1 = q.front().second;
			q.pop();
			if (x1 == dstx && y1 == dsty)
				return level;
			for (int i1 = 0; i1 < 8; i1++) {
				int x2 = x1 + dir[i1][0];
				int y2 = y1 + dir[i1][1];
				if (x2 < 0 || y2 < 0 || x2 >= I || y2 >= I)
					continue;
				if (check[x2][y2] == false) {
					q.push(make_pair(x2, y2));
					check[x2][y2] = true;
				}
			}
		}
		level++;
	}

}

int main() {
	int T;
	cin >> T;
	int depx, depy;
	

	for (int i = 0; i < T; i++) {
		scanf("%d", &I);
		scanf("%d %d", &depx, &depy);
		scanf("%d %d", &dstx, &dsty);
		printf("%d\n", BFS(depx, depy));
		memset(check, false, sizeof(check));
		
	}




}