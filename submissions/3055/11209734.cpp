#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

char graph[51][51];
int R, C;
pair <int, int> S;
pair <int, int> D;
bool check[51][51];
queue <pair <int, int>> water;
queue <pair <int, int>> hedgehog;
int dir[4][2] = { {-1, 0}, {1, 0}, { 0, -1}, { 0, 1} };

void WATER() {
	for (int i = 0; i < water.size(); i++) {
		int x1 = water.front().first;
		int y1 = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++) {
			int x2 = x1 + dir[i][0];
			int y2 = y1 + dir[i][1];
			if (x2 < 0 || y2 < 0 || x2 >= R || y2 >= C)
				continue;
			if (graph[x2][y2] == '.' ) {
				graph[x2][y2] = '*';
				water.push(make_pair(x2, y2));
			}
		}
	}
}
int BFS() {
	int time = 0;
	hedgehog.push(make_pair(S.first, S.second));

	while (!hedgehog.empty()) {
		WATER();
		int s = hedgehog.size();
		for (int i1 = 0; i1 < s; i1++) {
			int x1 = hedgehog.front().first;
			int y1 = hedgehog.front().second;
			hedgehog.pop();
			for (int i = 0; i < 4; i++) {
				int x2 = x1 + dir[i][0];
				int y2 = y1 + dir[i][1];
				if (x2 < 0 || y2 < 0 || x2 >= R || y2 >= C)
					continue;

				if (check[x2][y2] == false && graph[x2][y2] == '.') {
					hedgehog.push(make_pair(x2, y2));
					check[x2][y2] = true;
				}
				else if (graph[x2][y2] == 'D')
					return time + 1;

			}
		}

		time++;
	}

	return -1;
}


int main() {
	cin >> R >> C;
	char tmp;


	for (int i = 0; i < R; i++) {
		scanf("%c", &tmp);
		for (int j = 0; j < C; j++) {
			scanf("%c", &graph[i][j]);
			if (graph[i][j] == 'S') {
				S.first = i;
				S.second = j;
				graph[i][j] = '.';
			}
			else if (graph[i][j] == 'D') {
				D.first = i;
				D.second = j;
			}
			else if (graph[i][j] == '*') {
				water.push(make_pair(i, j));
			}
		}
	}



	int result = BFS();
	if (result == -1)
		cout << "KAKTUS";
	else
		cout << result;


}