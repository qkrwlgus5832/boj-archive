#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N;
char graph[101][101];

queue <pair <char, char>> q;
bool check[101][101];
void BFS(int x, int y) {
	q.push(make_pair(x, y));
	check[x][y] = true;
	char dd = graph[x][y];
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		if (x1 + 1 < N && check[x1 + 1][y1] == false && graph[x1 + 1][y1] == dd) {
			check[x1 + 1][y1] = true;
			q.push(make_pair(x1 + 1, y1));

		}
		if (y1 + 1 < N && check[x1][y1+1] == false && graph[x1][y1+1] == dd) {
			check[x1][y1+1] = true;
			q.push(make_pair(x1, y1+1));

		}
		if (x1 - 1 >=0  && check[x1 - 1][y1] == false && graph[x1 - 1][y1] == dd) {
			check[x1 - 1][y1] = true;
			q.push(make_pair(x1 - 1, y1));

		}
		if (y1- 1 >= 0 && check[x1][y1-1] == false && graph[x1][y1-1] == dd) {
			check[x1][y1-1] = true;
			q.push(make_pair(x1, y1-1));

		}

	}


}

void RGFS(int x, int y) {
	q.push(make_pair(x, y));
	check[x][y] = true;
	char dd = graph[x][y];
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		if (x1 + 1 < N && check[x1 + 1][y1] == false && graph[x1 + 1][y1] == dd) {
			check[x1 + 1][y1] = true;
			q.push(make_pair(x1 + 1, y1));

		}
		if (y1 + 1 < N && check[x1][y1 + 1] == false && graph[x1][y1 + 1] == dd) {
			check[x1][y1 + 1] = true;
			q.push(make_pair(x1, y1 + 1));

		}
		if (x1 - 1 >= 0 && check[x1 - 1][y1] == false && graph[x1 - 1][y1] == dd) {
			check[x1 - 1][y1] = true;
			q.push(make_pair(x1 - 1, y1));

		}
		if (y1 - 1 >= 0 && check[x1][y1 - 1] == false && graph[x1][y1 - 1] == dd) {
			check[x1][y1 - 1] = true;
			q.push(make_pair(x1, y1 - 1));

		}

	}


}
int main() {
	cin >> N;
	char dq;


	for (int i = 0; i < N; i++) {
		scanf("%1c", &dq);
		for (int j = 0; j < N; j++) {
			scanf("%1c", &graph[i][j]);

		}
	}



	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == false) {

				BFS(i, j);
				result++;
			}

		}
	}
	memset(check, 0, sizeof(check));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 'G')
				graph[i][j] = 'R';

		}
	}
	int result1 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == false) {

				BFS(i, j);
				result1++;
			}

		}
	}

	cout << result << " " << result1;

}
