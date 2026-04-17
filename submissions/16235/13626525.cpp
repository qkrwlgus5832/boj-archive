#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;

int nutrient[11][11];

int A[11][11];

deque <int> v[101];

int dir[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0},{1,1} };

int getgroundloaction(int i, int j) {
	return i*N + j;
}

void springAndSummer() {
	for (int i = 0; i < N*N; i++) {
		int f = 0;
		int tmpj = -1;
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].size(); j++) {
			if (nutrient[i / N][i % N] >= v[i][j]) {
				nutrient[i / N][i % N] -= v[i][j];
				v[i][j]++;
			}
			else {
				f = 1;
				tmpj = j;
				break;

			}
		}
		if (f == 1) {
			for (int j = tmpj; j < v[i].size(); j++) {
				nutrient[i / N][i % N] += (v[i][j] / 2);
			}

			int size = v[i].size();
			for (int j = tmpj; j < size; j++) {
				v[i].pop_back();
			}
		}
	}
}

void fall() {
	for (int i = 0; i < N*N; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] % 5 == 0) {
				for (int diri = 0; diri < 8; diri++) {
						int x = (i / N) + dir[diri][0];
						int y = (i % N) + dir[diri][1];
						if (x < 0 || y < 0 || x >= N || y >= N)
							continue;
						else
							v[x * N + y].push_front(1);
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

int getreuslt() {
	int result = 0;
	for (int i = 0; i < N*N; i++) {
		result += v[i].size();
	}
	return result;
}

int main() {
	
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			nutrient[i][j] = 5;
		}
	}

	int x, y, z;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &y, &x, &z);
		v[getgroundloaction(x - 1, y - 1)].push_back(z);
	}


	for (int i = 0; i < K; i++) {
		springAndSummer();
		fall();
		winter();
	}

	cout << getreuslt();
	//system("Pause");
}