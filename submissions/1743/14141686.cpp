#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;


char graph[101][101];
bool check[101][101];

int dir[4][2] = { {-1,0}, {1,0} ,{ 0 ,-1}, {0,1} };

int result = 0;

int BFS(int i, int j) {
	queue <pair <int, int>> q;
	q.push(make_pair(i, j));
	check[i][j] = true;
	int count = 1;
	while (!q.empty()) {
		int fronti = q.front().first;
		int frontj = q.front().second;

		q.pop();

		for (int i1 = 0; i1 < 4; i1++) {
			int nx = fronti + dir[i1][0];
			int ny = frontj + dir[i1][1];

			if (check[nx][ny] == false && graph[nx][ny] == 1) {
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
				count++;
			}
		}

	}
	return count;
}
int main() {
	cin.tie(NULL);
	cin >> N >> M >> K;
	int r, c;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		graph[r-1][c-1] = 1;
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 1 && check[i][j] == false)
				result= max(result,BFS(i, j));
		}
	}
	cout << result;
	//system("Pause");
}