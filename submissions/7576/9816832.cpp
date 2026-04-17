#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue <pair<int, int>> q;
int graph[1001][1001];
bool check[1001][1001];
int M, N;

int dirx[4] = {0,0,-1,1};
int diry[4] = {-1,1,0,0};
int bfs() {
	int count = 0;

	while (!q.empty()) {
		int a = q.size();
		int f = 0;
		for (int i = 0; i < a; i++){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		graph[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dirx[i];
			int ny = y + diry[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if (graph[nx][ny] == 0 && check[nx][ny] == false) {
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
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
	cin >> M >> N;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 1) {
				q.push(make_pair(i, j));
				check[i][j] = true;
			}
		}
	}

	 result = bfs();

	int fl = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				fl = 1;
				break;
			}

		}
	}
	if (fl == 1)
		cout << -1;
	else
		cout << result;

}