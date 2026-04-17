#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue <pair<char , pair<char, char>>> q;
int graph[101][101][101];
bool check[101][101][101];
int M, N, H;

int dirh[2] = { -1,1 };


int dirx[4] = {0,0,-1,1};
int diry[4] = {-1,1,0,0};
int bfs() {
	int count = 0;

	while (!q.empty()) {
		int a = q.size();
		int f = 0;
		for (int i = 0; i < a; i++){
		int h = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		graph[h][x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dirx[i];
			int ny = y + diry[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if (graph[h][nx][ny] == 0 && check[h][nx][ny] == false) {
				check[h][nx][ny] = true;
				q.push(make_pair(h,make_pair(nx, ny)));
				f = 1;

			}
		}

		for (int i = 0; i < 2; i++) {
			int nh = h + dirh[i];
			if (nh < 0 || nh >= H)
				continue;
			if (graph[nh][x][y] == 0 && check[nh][x][y] == false) {
				check[nh][x][y] = true;
				q.push(make_pair(nh, make_pair(x, y)));
				f = 1;
			}
		}
	}
		if (f==1)
		count++;
	}
	return count;

}
int main() {
	cin >> M >> N >> H;

	for (int i1 = 0; i1 < H; i1++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &graph[i1][i][j]);
			}
		}

	}

	int result = 0;



	for (int i1 = 0; i1 < H; i1++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i1][i][j] == 1) {
					q.push(make_pair(i1,make_pair(i, j)));
					check[i1][i][j] = true;
				}
			}
		}

	}




	 result = bfs();

	int fl = 0;
	for (int i1 = 0; i1 < H; i1++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i1][i][j] == 0) {
					fl = 1;
					break;
				}

			}
		}
	}


	if (fl == 1)
		cout << -1;
	else
		cout << result;

}