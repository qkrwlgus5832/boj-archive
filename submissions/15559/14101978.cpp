#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N, M;

int result = -1;

char graph[1001][1001];

bool check[1001][1001];

int dir[4][2] = { {-1, 0} ,{1,0}, {0, -1}, {0, 1} };


int queuepush(bool check2[][1001], int nx, int ny, queue <pair <int, int>>& q) {
	if (check2[nx][ny] == true)
		return 1;
	if (check[nx][ny] == true)
		return -1;
	check2[nx][ny] = true; check[nx][ny] = true;
	q.push(make_pair(nx, ny));
	return 0;
}


int BFS(int i, int j) {
	bool check2[1001][1001];
	queue <pair <int, int>> q;
	q.push(make_pair(i, j));
	check2[i][j] = true;
	check[i][j] = true;
	while (!q.empty()) {
		int fronti = q.front().first;
		int frontj = q.front().second;

		q.pop();

		if (graph[fronti][frontj] == 'N') {
			int nx = fronti + dir[0][0];
			int ny = frontj + dir[0][1];
			if (queuepush(check2, nx, ny, q) == 1)
				return 1;
			if (queuepush(check2, nx, ny, q) == -1)
				return 0;
		}

		else if (graph[fronti][frontj] == 'S') {
			int nx = fronti+ dir[1][0];
			int ny = frontj+ dir[1][1];
			if (queuepush(check2, nx, ny, q) == 1)
				return 1;
			if (queuepush(check2, nx, ny, q) == -1)
				return 0;
		}

		else if(graph[fronti][frontj] == 'W') {
			int nx = fronti + dir[2][0];
			int ny = frontj + dir[2][1];
			if (queuepush(check2, nx, ny, q) == 1)
				return 1;
			if (queuepush(check2, nx, ny, q) == -1)
				return 0;
		}
		else if (graph[fronti][frontj] == 'E') {
			int nx = fronti + dir[3][0];
			int ny = frontj+ dir[3][1];
			if (queuepush(check2, nx, ny, q) == 1)
				return 1;
			if (queuepush(check2, nx, ny, q) == -1)
				return 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == false) {
				result += BFS(i, j);
			}
		}
	}
	cout << result;
	//system("Pause");
}