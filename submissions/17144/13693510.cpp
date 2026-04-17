#define _CRT_SECURE_NO_WARNINGS
#define maxR 50
#define maxC 50
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int R, C, T;

int room[maxR+1][maxC+1];

int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

pair <int, int> aircleaner;

void settmproom(int tmproom[][maxC+1]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			tmproom[i][j] = room[i][j];
		}
	}
}

void setroom(int tmproom[][maxC + 1]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] == -1)
				continue;
			room[i][j] = tmproom[i][j];
		}
	}
}
//void BFS(int i, int j, int tmp[][maxC+1]) {
//	bool check[maxR + 1][maxC + 1];
//	memset(check, false, sizeof(check));
//	queue <pair <int, int>> q;
//	check[i][j] = true;
//	q.push(make_pair(i, j));
//
//	while (!q.empty()) {
//		int fronti = q.front().first;
//		int frontj = q.front().second;
//		int count = 0;
//		for (int i1 = 0; i1 < 4; i1++) {
//			int tmpi = fronti + dir[i1][0];
//			int tmpj = frontj + dir[i1][1];
//			if (tmpi < 0 || tmpj < 0 || tmpi >= maxR || tmpj >= maxC) {
//				continue;
//			}
//			count++;
//			if (check[tmpi][tmpj] == false && room[tmpi][tmpj] != -1) {
//				tmp[tmpi][tmpj] += 
//			}
//
//
//		}
//	}
//
//}

void aircleaning_counter_clock_wise(int i, int j, char direction, int beforemise) {
	int currentmise = room[i][j];
	if (direction == 'R') {
		room[i][j] = beforemise;
		if (j + 1 < C)
			aircleaning_counter_clock_wise(i, j + 1, 'R', currentmise);
		else
			aircleaning_counter_clock_wise(i - 1, j, 'U', currentmise);
	}
	else if (direction == 'U') {
		room[i][j] = beforemise;
		if (i - 1 >= 0)
			aircleaning_counter_clock_wise(i - 1, j, 'U', currentmise);
		else
			aircleaning_counter_clock_wise(i, j - 1, 'L', currentmise);
	}
	else if (direction == 'L') {
		room[i][j] = beforemise;
		if (j - 1 >= 0)
			aircleaning_counter_clock_wise( i , j-1, 'L', currentmise);
		else
			aircleaning_counter_clock_wise(i+1, j, 'D', currentmise);
	}
	else if (direction == 'D') {
		if (currentmise == -1) {
			room[i][j] = -1;
			return;
		}
		room[i][j] = beforemise;
		if (i + 1 < R)
			aircleaning_counter_clock_wise(i + 1, j, 'D', currentmise);
	
	}
}

void aircleaning_clock_wise(int i, int j, char direction, int beforemise) {
	if (direction == 'R') {
		int currentmise = room[i][j];
		room[i][j] = beforemise;
		if (j + 1 < C)
			aircleaning_clock_wise(i, j + 1, 'R', currentmise);
		else
			aircleaning_clock_wise(i + 1, j, 'D', currentmise);
	}
	else if (direction == 'D') {
		int currentmise = room[i][j];
		room[i][j] = beforemise;
		if ( i + 1 < R)
			aircleaning_clock_wise(i+ 1, j, 'D', currentmise);
		else
			aircleaning_clock_wise(i, j - 1, 'L', currentmise);

	}
	else if (direction == 'L') {
		int currentmise = room[i][j];
		room[i][j] = beforemise;
		if (j - 1 >= 0)
			aircleaning_clock_wise(i, j - 1, 'L', currentmise);
		else
			aircleaning_clock_wise(i-1, j, 'U', currentmise);
	}
	else if (direction == 'U') {
		int currentmise = room[i][j];
		if (currentmise == -1) {
			room[i][j] = -1;
			return;
		}
		room[i][j] = beforemise;
		if (i - 1 >= 0)
			aircleaning_clock_wise(i - 1, j, 'U', currentmise);
	}
	//else if (direction == 'D') {
	//	int currentmise = room[i][j];
	//	if (currentmise == -1) {
	//		return;
	//	}
	//	room[i][j] = beforemise;
	//	if (i + 1 < R)
	//		aircleaning_clock_wise(i + 1, j, 'D', currentmise);

	//}

}

int main() {
	cin >> R >> C >> T;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &room[i][j]);
			if (room[i][j] == -1) {
				aircleaner.first = i;
				aircleaner.second = j;
			}
		}
	}

	for (int i = 0; i < T; i++) {
		int tmproom[maxR + 1][maxC + 1] = { 0 };


		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (room[i][j] > 0) {
					int count = 0;
					for (int i1 = 0; i1 < 4; i1++) {
						int tmpi = i + dir[i1][0];
						int tmpj = j + dir[i1][1];
						if (tmpi < 0 || tmpj < 0 || tmpi >= R || tmpj >= C || room[tmpi][tmpj] == -1)
							continue;
						tmproom[tmpi][tmpj] += room[i][j] / 5;
						count++;
					}
					tmproom[i][j] += room[i][j] - (room[i][j] / 5) * count;
				}
			}
		}
	

		setroom(tmproom);


		int beforemise = room[aircleaner.first - 1][aircleaner.second + 1];
		room[aircleaner.first - 1][aircleaner.second + 1] = 0;

		aircleaning_counter_clock_wise(aircleaner.first - 1, aircleaner.second + 2, 'R', beforemise);


		beforemise = room[aircleaner.first][aircleaner.second + 1];
		room[aircleaner.first][aircleaner.second + 1] = 0;
		aircleaning_clock_wise(aircleaner.first, aircleaner.second + 2, 'R', beforemise);


	}
	int result = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] != -1)
				result += room[i][j];
		}
	}
	cout << result;
	//system("Pause");
}
