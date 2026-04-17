#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool check[1<<7][51][51];

char graph[51][51];

pair <int, int> startlocation;

int BFS(pair <int, int> start, int N, int M) {
	queue < pair <pair <int, int>, int>> q;
	q.push({ start, 0 });
	check[0][start.first][start.second] = true;
	int count = 0;
	while (!q.empty()) {
		int qsize = q.size();
		for (int node = 0; node < qsize; node++) {
			int fronti = q.front().first.first;
			int frontj = q.front().first.second;
			int key = q.front().second;
			q.pop();
			if (graph[fronti][frontj] == '1')
				return count;

			for (int diri = 0; diri < 4; diri++) {
				int ni = fronti + dir[diri][0];
				int nj = frontj + dir[diri][1];
				if (ni < 0 || nj < 0 || ni >= N || nj >= M)
					continue;
				if (graph[ni][nj] >= 'a' && graph[ni][nj] <= 'f' && check[key][ni][nj] == false) {
					int tmpkey = (key | (1 << (graph[ni][nj] - 'a')));
					check[tmpkey][ni][nj] = true;
					q.push({ {ni,nj}, tmpkey });
				}
				else if (graph[ni][nj] >= 'A' && graph[ni][nj] <= 'F') {
					if ((key & (1 << (graph[ni][nj] - 'A'))) > 0 && check[key][ni][nj] == false) {
						check[key][ni][nj] = true;
						q.push({ {ni,nj},key });
					}
				}
				else if (graph[ni][nj] != '#') {
					if (check[key][ni][nj] == false) {
						check[key][ni][nj] = true;
						q.push({ { ni,nj },key });
					}
				}
			}
		}
		count++;
	}
	return -1;
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == '0')
				startlocation = { i,j };
		}
	}
	cout << BFS(startlocation, N, M);
	//system("Pause");
}