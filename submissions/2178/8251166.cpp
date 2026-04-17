#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int map[101][101];
bool check[101][101];
int N;
int M;

queue <int> q;

int findPath_BFS(int i, int j) {
	int level = 1;
	q.push(i*M + j);
	

	check[i][j] = true;
	while (!q.empty()) {
		int a2 = q.size();	
		int f = 0;
		for (int i = 0; i < a2; i++) {
			int tmp2 = q.front();
			q.pop();
			int x2 = tmp2 / M;
			int y2 = tmp2 % M;
			if (map[x2 - 1][y2] == 1 && x2 - 1 >= 0 && check[x2 - 1][y2] == false) {
				f = 1;
				check[x2 - 1][y2] = true;
				q.push((x2 - 1) * M + y2);
				if (x2 - 1 == N - 1 && y2 - 1 == M - 1)
					return level+1;

			}
			if (map[x2 + 1][y2] == 1 && x2 + 1 <= N - 1 && check[x2 + 1][y2] == false) {
				f = 1;
				check[x2 + 1][y2] = true;
				q.push((x2 + 1)*M + y2);
				if (x2+1  == N - 1 && y2 == M - 1)
					return level+1;

			}
			if (map[x2][y2 - 1] == 1 && y2 - 1 >= 0 && check[x2][y2 - 1] == false) {
				f = 1;
				check[x2][y2 - 1] = true;
				q.push(x2*M + y2 - 1);
				if (x2  == N - 1 && y2 - 1 == M - 1)
					return level+1;

			}
			if (map[x2][y2 + 1] == 1 && y2 + 1 <= M - 1 && check[x2][y2 + 1] == false) {
				f = 1;
				check[x2][y2 + 1] = true;
				q.push(x2*M + y2 + 1);
				if (x2 == N - 1 && y2 + 1 == M - 1)
					return level+1;
			}			
		}
		if (f == 1)
			level = level + 1;
	}

}


int main() {
		cin >> N >> M;


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%1d", &map[i][j]);
			}
		}



		cout << findPath_BFS(0, 0);

}
