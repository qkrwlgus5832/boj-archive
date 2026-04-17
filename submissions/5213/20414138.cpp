#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int N;
int graph[501][1001];
int m[501][1001];

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int getCount(int i) {
	if (i % 2 == 0) {
		return N;
	}
	return N - 1;
}

pair <int, int> getIndex(int i, int j) {
	if (j + 1 < 2 * N && m[i][j] == m[i][j + 1])
		return { i,j + 1 };
	return { i,j - 1 };
}
int BFS(int i, int j, int count) {
	queue <pair <pair <int, int>, vector <int>>> q;
	vector<int> v;
	v.push_back(1);
	q.push({ {i,j},  v });
	q.push({ getIndex(i,j), v });
	int bfscheck[501 * 501] = { 0, };

	int depth = 0;
	int maxIndex = 1;
	bool flag = false;
	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			pair <pair <int, int>, vector <int>> front = q.front();
			q.pop();
			if (m[front.first.first][front.first.second] == count) {
				printf("%d\n", front.second.size());
				for (int i1 = 0; i1 < front.second.size(); i1++) {
					printf("%d ", front.second[i1]);
				}
				return 0;
			}
			maxIndex = max(maxIndex, m[front.first.first][front.first.second]);

			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.first.first + dir[i1][0];
				int nj = front.first.second + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= N || nj >= 2 * N)
					continue;

				else if (bfscheck[m[ni][nj]] == true)
					continue;

			
				if (graph[ni][nj] == graph[front.first.first][front.first.second]) {
					front.second.push_back(m[ni][nj]);
					bfscheck[m[ni][nj]]++;
					q.push({ { ni,nj }, front.second });
					q.push({ {getIndex(ni, nj)}, front.second});
					front.second.pop_back();

				}
			}

		}
		depth++;
	}
	
	return maxIndex;
}

bool maxIndexBFS(int i, int j, int maxIndex) {
	queue <pair <pair <int, int>, vector <int>>> q;
	vector <int> v;
	v.push_back(1);
	q.push({ {i,j}, v });
	q.push({ getIndex(i,j), v });
	bool bfscheck[501* 501] = { false, };

	int depth = 0;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			pair <pair <int, int>, vector <int>> front = q.front();
			q.pop();
			if (m[front.first.first][front.first.second] == maxIndex) {
				printf("%d\n", front.second.size());
				for (int i1 = 0; i1 < front.second.size(); i1++) {
					printf("%d ", front.second[i1]);
				}
				return true;
			}
			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.first.first + dir[i1][0];
				int nj = front.first.second + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= N || nj >= 2 * N)
					continue;
				if (bfscheck[m[ni][nj]] == 1)
					continue;

				else if (graph[ni][nj] == graph[front.first.first][front.first.second]) {
					bfscheck[m[ni][nj]]++;
					front.second.push_back(m[ni][nj]);
					q.push({ { ni,nj }, front.second });
					q.push({ getIndex(ni,nj), front.second });
					front.second.pop_back();
				}
			}

		}
		depth++;
	}
	return false;
}
int main() {
	cin >> N;

	int i = 0;
	int j = 0;
	int count = 1;

	int A, B;

	int maxValue = 0;

	for (int i = 0; i < N; i++) {
		int tmp = getCount(i);
		if (tmp == N) {
			for (int j = 0, j1 = 0; j1 < tmp; j += 2, j1++) {
				scanf("%d %d", &A, &B);
				graph[i][j] = A;  m[i][j] = count;
				graph[i][j + 1] = B; m[i][j + 1] = count;
				count++;
			}
		}
		if (tmp == N - 1) {
			for (int j = 1, j1 = 0; j1 < tmp; j += 2, j1++) {
				scanf("%d %d", &A, &B);
				graph[i][j] = A; m[i][j] = count;
				graph[i][j + 1] = B; m[i][j + 1] = count;
				count++;
			}
		}
	}
	int maxIndex = BFS(0, 0, count - 1);
	if (maxIndex > 0) {
		maxIndexBFS(0, 0, maxIndex);
	}
//	system("Pause");
}