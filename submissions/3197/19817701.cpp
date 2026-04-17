#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

char origingraph[1501][1501];

char graph[1501][1501];
bool check[1501][1501];

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

char tmpgraph[1501][1501];

int meltingPoint[1501][1501];

int R, C;

void BFS(int i, int j, int count, int day) {
	check[i][j] = true;
	queue <pair <int, int>> q;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		pair <int, int> front = q.front();
		q.pop();

		for (int j = 0; j< 4; j++) {
			int ni = front.first + dir[j][0];
			int nj = front.second + dir[j][1];

			if (ni < 0 || nj < 0 || ni >= R || nj >= C)
				continue;
			if ((meltingPoint[ni][nj] <=day || graph[ni][nj] == 'L') && check[ni][nj] == false) {
				check[ni][nj] = true;
				if (graph[ni][nj] == 'L')
					return;
				q.push(make_pair(ni, nj));
			}
		}
	}

}

bool checkIfAnswer(int count, int day) {
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
					BFS(i, j, count, day);
					flag = true;
				}
			}
		}
	}
	return true;
}
void melting(int day) {

	memcpy(graph, origingraph, sizeof(origingraph));
	for (int k = 1; k <= day; k++) {
		bool flag = false;

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
							meltingPoint[ni][nj] = k;
							flag = true;
						}
					}
				}
			}
		}
		if (flag == false)
			return;
	}
}
int binary_search(int start, int end, int count) {
	if (start == end) {
		return start;
	}
	else if (start + 1 == end) {
		if (checkIfAnswer(count, start))
			return start;
		else
			return end;
	}

	if (checkIfAnswer(count, (start + end) / 2))
		return binary_search(start, (start + end) / 2, count);
	else
		return binary_search((start + end) / 2 + 1, end, count);
}

int main() {

	cin >> R >> C;
	
	char tmp;

	int count = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> origingraph[i][j];
			if (origingraph[i][j] == 'L') {
				count++;
			}
			if (origingraph[i][j] == '.') {
				meltingPoint[i][j] = 0;
			}
		}
	}
	melting(1500 * 1500);
	cout << binary_search(0, 1500 * 1500, count);

	//system("Pause");
}