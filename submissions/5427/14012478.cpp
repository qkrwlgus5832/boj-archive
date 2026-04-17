#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

char graph[1001][1001];

int dir[4][2] = { {-1,0}, {1, 0}, {0, -1}, {0, 1} };

deque <pair <int, int>> fire;

void fireBFS(int w, int h) {

	int s = fire.size();

	for (int i = 0; i < s; i++) {
		int fronti = fire.front().first;
		int frontj = fire.front().second;
		fire.pop_front();
		for (int i1 = 0; i1 < 4; i1++) {
			int nx = fronti + dir[i1][0];
			int ny = frontj + dir[i1][1];

			if (nx < 0 || ny < 0 || nx >= h || ny >= w)
				continue;
				
			if (graph[nx][ny] == '.' || graph[nx][ny] == '@') {
				graph[nx][ny] = '*';
				fire.push_back(make_pair(nx, ny));
			}
		}

	}

}



int BFS(int w, int h, pair <int, int> sangeonlocation) {
	queue <pair <int, int>> sangeon;
	sangeon.push(sangeonlocation);
	int time = 0;
	while (!sangeon.empty()) {
		int s = sangeon.size();
		for (int i = 0; i < s; i++) {
			int fronti = sangeon.front().first;
			int frontj = sangeon.front().second;
			sangeon.pop();
			
			for (int i1 = 0; i1 < 4; i1++) {
				int nx = fronti + dir[i1][0];
				int ny = frontj + dir[i1][1];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
					return time + 1;
				}
				if ( graph[nx][ny] == '.') {
					graph[nx][ny] = '@';
					sangeon.push(make_pair(nx, ny));
				}
			}
		}
		fireBFS(w, h);
		time++;

	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	int w, h;
	pair <int, int> sangeonloaction;

	char tmp;

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &w, &h);
		memset(graph, 0, sizeof(graph));
		fire.clear();

		for (int i1 = 0; i1 < h; i1++) {
			scanf("%c", &tmp);
			for (int j1 = 0; j1 < w; j1++) {
				
				scanf("%1c", &graph[i1][j1]);
				if (graph[i1][j1] == '@') {
					sangeonloaction.first = i1;
					sangeonloaction.second = j1;
				}
				else if (graph[i1][j1] == '*') {
					fire.push_back(make_pair(i1, j1));
				}
			}
		}
	

		int result = BFS(w, h, sangeonloaction);
		if (result != -1)
			printf("%d\n", result);
		else
			printf("IMPOSSIBLE\n");
		
	}
	//system("Pause");
}