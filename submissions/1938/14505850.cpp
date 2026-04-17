#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

char graph[51][51];

int global_dir[4][2] = { {-1,0}, {1, 0}, {0, -1}, {0, 1} };

bool check[51][51][2];
int N;

class tree {
public:
	int x;
	int y;
	char dir;
	int count;
	tree(int x, int y, char dir, int count) {
		this->x = x;
		this->y = y;
		this->dir = dir;
		this->count = count;
	}
};

bool isNotInRange(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N)
		return true;
	if (graph[x][y] == '1')
		return true;
	else
		return false;

}

bool canRotate(int x, int y, char dir) {
	if (dir == 1) {
		for (int i = -1; i <= 1; i++) {
			if (i == 0)
				continue;
			for (int j = -1; j <= 1; j++) {
				int nx = x + i;
				int ny = y + j;
				if (isNotInRange(nx,ny))
					return false;
				else if (graph[nx][ny] == '1')
					return false;
			}
		}

	}
	else if (dir == 0) {
		for (int i = -1; i <= 1; i++) {

			for (int j = -1; j <= 1; j++) {
				if (j == 0)
					continue;
				int nx = x + i;
				int ny = y + j;
				if (isNotInRange(nx, ny))
					return false;
				else if (graph[nx][ny] == '1')
					return false;

			}
		}
	}
	return true;
}
int BFS(int i, int j, char dir) {
	queue <tree> q;
	q.push(tree(i, j, dir, 0));
	check[i][j][dir] = true;

	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			tree tmp = q.front();
			q.pop();
			if (graph[tmp.x][tmp.y] == 'E') {
				if (tmp.dir == 0) {
					if (graph[tmp.x - 1][tmp.y] == 'E' && graph[tmp.x + 1][tmp.y] == 'E')
						return tmp.count;
				}
				else if (tmp.dir == 1) {
					if (graph[tmp.x][tmp.y - 1] == 'E' && graph[tmp.x][tmp.y + 1] == 'E')
						return tmp.count;
				}
			}
			for (int i1 = 0; i1 < 4; i1++) {
				int nx = tmp.x + global_dir[i1][0];
				int ny = tmp.y + global_dir[i1][1];
				if (isNotInRange(nx, ny))
					continue;
				if (tmp.dir == 0) {
					if (isNotInRange(nx - 1, ny))
						continue;
					if (isNotInRange(nx + 1, ny))
						continue;
				}
				if (tmp.dir == 1) {
					if (isNotInRange(nx, ny - 1))
						continue;
					if (isNotInRange(nx, ny + 1))
						continue;
				}
				if (check[nx][ny][tmp.dir] == false) {
					q.push(tree(nx, ny, tmp.dir, tmp.count + 1));
					check[nx][ny][tmp.dir] = true;
				}
			}
			if (canRotate(tmp.x, tmp.y, tmp.dir) && check[tmp.x][tmp.y][!tmp.dir] == false) {
				tmp.count++;
				tmp.dir = !tmp.dir;
				q.push(tmp);
				check[tmp.x][tmp.y][tmp.dir] = true;
			}
		}
	}


}
int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	int f = 0;

	//cout << BFS(2, 3, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 'B') {
				if (graph[i + 1][j] == 'B') {
					cout << BFS(i + 1, j, 0);
					f = 1;
					break;
				}
				else if (graph[i][j + 1] == 'B') {
					cout << BFS(i, j + 1, 1);
					f = 1;
					break;
				}
			}
		}
		if (f == 1)
			break;
	}
	//system("Pause");
}