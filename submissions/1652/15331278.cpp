#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

char graph[101][101];
bool check[101][101];


int dir[2][2] = {{ 1, 0 }, { 0,1 }};

int BFS(int i, int j, int i1) {
	queue <pair <int, int>> q;
	check[i][j] = true;
	q.push(make_pair(i, j));

	int count = 1;

	while (!q.empty()) {
		pair <int, int> front = q.front();
		int ni = front.first + dir[i1][0];
		int nj = front.second + dir[i1][1];
		q.pop();

		if (check[ni][nj] == false && graph[ni][nj] == '.') {
			check[ni][nj] = true;
			count++;
			q.push(make_pair(ni, nj));
		}
	}
	return count;
}




int main() {
	int N;
	cin >> N;

	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	int rowcount = 0;
	int colcount = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == '.' &&check[i][j] == false) {
				if (BFS(i, j, 1) >= 2)
					rowcount++;
			}
		}
	}
	memset(check, false, sizeof(check));
	
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (graph[i][j] == '.' && check[i][j] == false) {
				if (BFS(i, j, 0) >= 2)
					colcount++;
			}
		}
	}
	cout << rowcount << " " << colcount;
	//system("Pause");
}