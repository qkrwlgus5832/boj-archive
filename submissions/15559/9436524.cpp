#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

queue <int> q;

int check2[1001][1001];
bool check[1001][1001];
char graph[1001][1001];

int N, M;

int BFScycle(int x, int y, int count) {
	q.push(x*M + y);
	check[x][y] = true;
	while (!q.empty()) {
		int x1 = q.front() / M;
		int y1 = q.front() % M;
		q.pop();
		int nx = x1;
		int ny = y1;
		if (graph[x1][y1] == 'S')
			nx = nx + 1;
		else if (graph[x1][y1] == 'E')
			ny = ny + 1;
		else if (graph[x1][y1] == 'N')
			nx = nx - 1;
		else if (graph[x1][y1] == 'W')
			ny = ny - 1;
		
			if (check[nx][ny] == true) {
				return check2[nx][ny];
				
			}
			else if (check2[nx][ny] == 0) {
				q.push((nx)*M + ny);
				check2[nx][ny] = ++count;
				check[nx][ny] = true;
			}

	}

	return count;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}


	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check2[i][j] == 0) {
				check2[i][j] = 1;
				result += BFScycle(i, j,1);
				memset(check, false, sizeof(check));
			}
		}
	}
	cout << result;
}