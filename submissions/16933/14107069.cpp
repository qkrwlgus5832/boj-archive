#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;

class movenode {
public:
	int x;
	int y;
	char flag;
	int count;
	bool issunny;
};


queue <movenode> q;
int k;
bool graph[1001][1001];
bool check[1001][1001][11];

int dir[5][2] = { { -1, 0 }, {1, 0} , {0, -1}, {0, 1}, {0,0}};

void qpush(int x, int y, int dd, int flag, int count, bool issunny) {
	if (dd == 1)
		flag = flag + 1;

	movenode tmp;

	for (int i = 0; i < 5; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;

		if (i<4 && (graph[nx][ny] != dd || check[nx][ny][flag] == true))
			continue;

		tmp.x = nx; tmp.y = ny; tmp.flag = flag; tmp.count = count + 1; tmp.issunny = !issunny;
		q.push(tmp);
		check[nx][ny][flag] = true;
	}
	
}


int BFS(int x, int y) {
	movenode tmp;
	tmp.x = x; tmp.y = y; tmp.flag = false; tmp.count = 1; tmp.issunny = true;
	q.push(tmp);

	check[x][y][0] = true;
	while (!q.empty()) {
		int ss = q.size();
		for (int i = 0; i < ss; i++) {
			x = q.front().x;
			y = q.front().y;
			char flag = q.front().flag;
			int count = q.front().count;
			bool issunny = q.front().issunny;

			q.pop();
			if (x == N - 1 && y == M - 1)
				return count;
			if (issunny == true) {
				if (flag < k) {
					qpush(x, y, 1, flag, count , issunny);
				}
			}
			qpush(x, y, 0, flag, count, issunny);
		}


	}

	return -1;
}

int main() {
	cin >> N >> M >> k;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &graph[i][j]);

		}
	}

	cout << BFS(0, 0);
	//system("Pause");

}