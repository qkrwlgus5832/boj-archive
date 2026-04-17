#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <memory.h>

using namespace std;

int graph[11][11];
int N, M;

class node {
public:
	int x;
	int y;
	int time;
	bool flag = false;

	node(int x, int y, int time, bool flag) {
		this->x = x;
		this->y = y;
		this->time = time;
		this->flag = flag;
	}
};
int dir[4][2] = { { -1,0 }, { 1,0 },{0,-1},{0,1} };


int getCalculatedTime(int time, int graphValue) {
	if (time > graphValue) {
		return ((time / graphValue) + 1) * graphValue;
	}
	else if (time < graphValue) {
		return graphValue;
	}
}

int BFS(int i, int j) {
	queue <node> q;

	q.push(node(i, j, 0, false));

	int time = 0;

	int check[11][11] = { -1, };
	memset(check, 1, sizeof(check));

	check[i][j] = 0;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			node front = q.front();
			q.pop();
			if (front.x == N - 1 && front.y == N - 1)
				continue;
			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.x + dir[i1][0];
				int nj = front.y + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= N || nj >= N)
					continue;
				if (graph[ni][nj] == 0)
					continue;
				if (graph[ni][nj] >= 2 && ((front.time + 1) % graph[ni][nj] != 0 || front.flag)) {
					if ((front.time + 1) % graph[ni][nj] != 0) {
						int tmpTime = getCalculatedTime(front.time + 1, graph[ni][nj]);
						if (check[ni][nj] > tmpTime) {
							check[ni][nj] = tmpTime;
							q.push(node(ni, nj, tmpTime, false));
						}
					}
					continue;
				}
				if (check[ni][nj] <= front.time + 1)
					continue;

				check[ni][nj] = front.time + 1;
				if (graph[ni][nj] >= 2) {
					q.push(node(ni, nj, front.time + 1, true));
				}
				else {
					q.push(node(ni, nj, front.time + 1, false));
				}
			}
		}
		time++;
	}
	if (check[N - 1][N - 1] == -1)
		return INT_MAX;
	else
		return check[N - 1][N - 1];
}


bool checkIfCan(int i, int j) {

	if ((j + 1 < N && graph[i][j + 1] == 0) || (j - 1 >= 0 && graph[i][j - 1] == 0)) {
		if (i + 1 < N && graph[i + 1][j] == 0 || (i-1) >=0 && graph[i - 1][j] == 0)
			return false;
	}
	return true;
}
int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	int result = BFS(0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 0) {
				if (checkIfCan(i, j) == false)
					continue;
				graph[i][j] = M;
				result = min(result, BFS(0, 0));
				graph[i][j] = 0;
			}
		}
	}

	cout << result;
	//system("Pause");
}