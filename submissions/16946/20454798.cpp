#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <queue>
#include <map>
using namespace std;

int N, M;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int graph[1001][1001];
int check[1001][1001][2];

int result[1001][1001];


void BFS(int i, int j, int index) {
	queue <pair <int, int>> q;
	q.push({ i,j });
	check[i][j][0] = true;
	check[i][j][1] = index;

	vector <pair <int, int>> v;
	v.push_back({ i,j });
	int count = 1;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			pair <int,int> front = q.front();
			q.pop();

			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.first + dir[i1][0];
				int nj = front.second + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= N || nj >= M)
					continue;

				if (graph[ni][nj] == 0 && check[ni][nj][0] == false) {
					check[ni][nj][0] = true;
					check[ni][nj][1] = index;
					count++;
					v.push_back({ ni,nj });
					q.push({ ni,nj });
				}
			}
		}
		
	}
	for (int i = 0; i < v.size(); i++) {
		check[v[i].first][v[i].second][0] = count;
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	int index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0 && check[i][j][0] == false) {
				BFS(i, j, index);
				index++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 1) {
				map <int, int> m;
				for (int i1 = 0; i1 < 4; i1++) {
					int ni = i + dir[i1][0];
					int nj = j + dir[i1][1];
					if (ni < 0 || nj < 0 || ni >= N || nj >= M)
						continue;
					if (graph[ni][nj] == 0 && m.count(check[ni][nj][1]) ==0) {
						result[i][j] += check[ni][nj][0];
						m[check[ni][nj][1]] = 1;
					}
				}
				result[i][j]++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d", result[i][j] % 10);
		}
		printf("\n");

	}
	//system("Pause");
}
