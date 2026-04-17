#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M, T;

vector <deque <int>> v;

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

void clockwise(int x) {
	int tmp = v[x].back();
	v[x].pop_back();
	v[x].push_front(tmp);
}
void anticlockwise(int x) {
	int tmp = v[x].front();
	v[x].pop_front();
	v[x].push_back(tmp);
}
void check();
void rotate(int x, int d, int k) {
	if (d == 0) {
		for (int j = x; j <= N; j += x) {
			for (int i = 0; i < k; i++) {
				clockwise(j - 1);
			}
		}
	}
	else {
		for (int j = x; j <= N; j += x) {
			for (int i = 0; i < k; i++) {
				anticlockwise(j - 1);
			}
		}
	}
	
}
void check() {
	bool check[51][51] = { false, };
	bool flag = false;
	int value = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 0)
				continue;
			value += v[i][j];
			count++;
			for (int i1 = 0; i1 < 4; i1++) {
				int ni = i + dir[i1][0];
				int nj = j + dir[i1][1];

				if (ni < 0 || ni >= N)
					continue;

				if (nj == -1) {
					nj = M - 1;
				}
				if (nj == M) {
					nj = 0;
				}

				if (v[i][j] == v[ni][nj]) {
					check[i][j] = true;
					check[ni][nj] = true;
					flag = true;
				}
			}
		}

	}
	if (flag == true) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (check[i][j] == true) {
					v[i][j] = 0;
				}
			}
		}
	}
	else {
		double avg = (double) value / count;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (v[i][j] > 0) {
					if (v[i][j] > avg) {
						v[i][j]--;
					}
					else if (v[i][j] < avg){
						v[i][j]++;
					}
				}
			}
		}
	}
}
int main() {
	cin >> N >> M >> T;
	
	v.resize(N + 1);

	int tmp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &tmp);
			v[i].push_back(tmp);
		}
	}

	int x, d, k;

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &x, &d, &k);
		rotate(x, d, k);
		check();
	}


	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] > 0) {
				result += v[i][j];
			}
		}
	}
	cout << result;
	//system("Pause");
}
