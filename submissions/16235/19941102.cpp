#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;


int N, M, K;

deque <int> graph[11][11];
int nutrient[11][11];
int A[11][11];

int dir[8][2] = {
{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}
};

void springAndSummer() {
	for (int i=0; i<N; i++){
		for (int j = 0; j < N; j++) {
			int s = graph[i][j].size();
			int count = 0;
			for (int i1 = 0; i1 < s; i1++) {
				if (graph[i][j][i1] <= nutrient[i][j]) {
					nutrient[i][j] -= graph[i][j][i1];
					graph[i][j][i1]++;
					count++;
				}
				else {
					break;
				}
			}

			for (int i1 = 0; i1 < s - count; i1++) {
				nutrient[i][j] += (graph[i][j].back()) / 2;
				graph[i][j].pop_back();

			}
		}
	}
}

void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int i1 = 0; i1 < graph[i][j].size(); i1++) {
				if (graph[i][j][i1] % 5 == 0) {
					for (int i2 = 0; i2 < 8; i2++) {
						int ni = i + dir[i2][0];
						int nj = j + dir[i2][1];
						if (ni < 0 || nj < 0 || ni >= N || nj >= N)
							continue;
						graph[ni][nj].push_front(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			nutrient[i][j] += A[i][j];
		}
	}
}
int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			nutrient[i][j] = 5;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	int x, y, age;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &age);
		graph[--x][--y].push_back(age);
	}

	for (int i = 0; i < K; i++) {
		springAndSummer();
		fall();
		winter();
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result += graph[i][j].size();
		}
	}
	cout << result;
	//system("Pause");
}