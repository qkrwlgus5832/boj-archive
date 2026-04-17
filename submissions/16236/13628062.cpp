#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;


int N;

int ocean[21][21];

pair <int, int> babyshark;

int babysharksize = 2;

int dir[4][2] = { {-1,0}, {1,0}, {0, -1}, {0, 1} };
int BFS(int i, int j) {
	bool check[21][21];
	queue <pair <int, int>> q;
	memset(check, false, sizeof(check));

	check[i][j] = true;
	q.push(make_pair(i, j));

	int time = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int fronti = q.front().first;
			int frontj = q.front().second;

			q.pop();

			if (fronti == babyshark.first && frontj == babyshark.second)
				return time;

			for (int i = 0; i < 4; i++) {
				int tmpi = fronti + dir[i][0];
				int tmpj = frontj + dir[i][1];
				if (tmpi < 0 || tmpj < 0 || tmpi >= N || tmpj >= N)
					continue;
				if (ocean[tmpi][tmpj] <= babysharksize && check[tmpi][tmpj] == false) {
					q.push(make_pair(tmpi, tmpj));
					check[tmpi][tmpj] = true;
				}
			}
			
		}
		time++;
	}

	return -1;
}

int main() {
	cin >> N;
	pair <int, int> tmpbabyshark;
	int tmpbabysharksize = 0;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &ocean[i][j]);
			if (ocean[i][j] == 9) {
				babyshark.first = i;
				babyshark.second = j;
				ocean[babyshark.first][babyshark.second] = 0;
			}

		}
	}

	int sumresult = 0;
	while (1) {
		bool flag = false;
		int result = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == babyshark.first && j == babyshark.second)
					continue;
				if (ocean[i][j] < babysharksize && ocean[i][j] != 0) {
					int timecount = BFS(i, j);
					if (timecount != -1)
					{
						if (result == -1) {
							result = timecount;
							tmpbabyshark = make_pair(i, j);
							flag = true;
						}
						else if (result > timecount){
							result = min(timecount, result);
							tmpbabyshark = make_pair(i, j);
						}

					}
				}
			}
		}
		if (flag == true) {
			babyshark = tmpbabyshark;
			ocean[babyshark.first][babyshark.second] = 0;
			tmpbabysharksize += 1;
			if (tmpbabysharksize == babysharksize) {
				babysharksize++;
				tmpbabysharksize = 0;
			}
			sumresult += result;
		}
		else {
			break;
		}
	}
	cout << sumresult;
	//system("Pause");
}