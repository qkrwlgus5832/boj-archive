#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int cheese[101][101];
bool isExternalcheck[101][101];

int dir[4][2] = { {-1, 0}, {1,0} ,{ 0, -1}, {0,1} };

int N, M;



void checkExternalBFS(int i, int j) {
	queue <pair <int, int>> q;
	q.push(make_pair(i, j));
	isExternalcheck[i][j] = true;

	while (!q.empty()) {
		int fronti = q.front().first;
		int frontj = q.front().second;
		q.pop();

		for (int i1 = 0; i1 < 4; i1++) {
			int ni = fronti + dir[i1][0];
			int nj = frontj + dir[i1][1];
			if (ni < 0 || nj < 0 || ni >= N || nj >= M)
				continue;
			if (cheese[ni][nj] == 0 && isExternalcheck[ni][nj] == false) {
				q.push(make_pair(ni, nj));
				isExternalcheck[ni][nj] = true;
			}
		}

	}
}


int main() {
	cin >> N >> M;
	cin.tie(NULL);
	int count = 0;

	int time = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cheese[i][j];
			if (cheese[i][j] == 1 && time == 0) {
				count += 1;
				time = 1;
			}
			else if (cheese[i][j] == 1) {
				count += 1;
			}
		}
	}
	
	
	while (1) {
		memset(isExternalcheck, false, sizeof(isExternalcheck));
		for (int j = 0; j < M; j++) {
			if (isExternalcheck[0][j] == 0) {
				checkExternalBFS(0, j);
			}
			if (isExternalcheck[N-1][j] == 0) {
				checkExternalBFS(N-1, j);
			}
		}
		for (int i = 0; i < N; i++) {
			if (isExternalcheck[i][0] == 0) {
				checkExternalBFS(i, 0);
			}
			if (isExternalcheck[i][M - 1] == 0) {
				checkExternalBFS(i, M - 1);
			}
		}

		int tmpcount = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (cheese[i][j] == 1) {
					int count = 0;
					for (int i1 = 0; i1 < 4; i1++) {
						int ni = i + dir[i1][0];
						int nj = j + dir[i1][1];
						if (isExternalcheck[ni][nj] == true && cheese[ni][nj] == 0) {
							count++;
							//cheese[i][j] = 0;
							if (count == 2)
								break;
						}
							
					}
					if (count == 2)
						cheese[i][j] = 0;
					tmpcount += cheese[i][j];
				}
			}
		}
		if (tmpcount == 0) {
			cout << time;
			break;
		}
		else {
			count = tmpcount;
			time++;
		}
	}
		//system("Pause");
}