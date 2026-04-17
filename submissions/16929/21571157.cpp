#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int N, M;

bool check[51][51];

char graph[51][51];

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int reverseDir[4] = { 1, 0, 3, 2 };

typedef struct {
	int x;
	int y;
	int dir;

} node;


bool BFS(int i, int j) {
	queue <node> q;
	bool bfscheck[51][51] = { false, };

	bfscheck[i][j] = true;
	check[i][j] = true;
	q.push({ i,j, -1 });

	while (q.size()) {
		node front = q.front();
		q.pop();

		for (int i1 = 0; i1 < 4; i1++) {
			if (i1 == reverseDir[front.dir])
				continue;

			int ni = front.x + dir[i1][0];
			int nj = front.y + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M)
				continue;

			else if (bfscheck[ni][nj] == true)
				return true;

			if (check[ni][nj] == false && graph[ni][nj] == graph[i][j]) {
				check[ni][nj] = true;
				bfscheck[ni][nj] = true;
				q.push({ ni,nj, i1 });
			}
		}
	}
	return false;
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	bool result = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == false) {
				result = result || BFS(i, j);

			}
		}
	}
	if (result)
		cout << "Yes";
	else
		cout << "No";
	//system("Pause");
}