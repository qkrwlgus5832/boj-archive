#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

char graph[1501][1501];
bool check[1501][1501];

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

char tmpgraph[1501][1501];

int R, C;

int BFS(int i, int j, int count, int currentcount) {
	check[i][j] = true;
	queue <pair <int, int>> q;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		pair <int, int> front = q.front();
		q.pop();

		for (int j = 0; j< 4; j++) {
			int ni = front.first + dir[j][0];
			int nj = front.second + dir[j][1];

			if ((graph[ni][nj] == '.' || graph[ni][nj] == 'L') && check[ni][nj] == false) {
				if (graph[ni][nj] == 'L')
					currentcount++;
			
				check[ni][nj] = true;
				if (currentcount == count) {
					return currentcount;
				}

				q.push(make_pair(ni, nj));
			}
		}
	}
	return currentcount;
}

bool checkIfAnswer(int count) {
	memset(check, false, sizeof(check));

	bool flag = false;
	
	int currentcount = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] == 'L' && check[i][j] == false) {
				if (flag == true) {
					return false;
				}
				else {
					currentcount = BFS(i, j, count, currentcount);
					flag = true;
				}
			}
		}
	}
	return true;
}

void melting() {

	memcpy(tmpgraph, graph, sizeof(graph));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (tmpgraph[i][j] == '.' || tmpgraph[i][j] == 'L') {
				for (int i1 = 0; i1 < 4; i1++) {
					int ni = i + dir[i1][0];
					int nj = j + dir[i1][1];
					if (ni < 0 || nj < 0 || ni >= R || nj >= C) {
						continue;
					}
					if (tmpgraph[ni][nj] == 'X') {
						graph[ni][nj] = '.';
					}
				}
			}
		}
	}
}
int main() {

	cin >> R >> C;
	
	char tmp;

	int count = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'L') {
				count++;
			}
		}
	}

	int day = 0;
	while (1) {
		if (checkIfAnswer(count)) {
			cout << day;
			break;
		}
		melting();
		day++;
	}
	//system("Pause");
}