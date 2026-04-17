#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;



int N, M;
queue <pair <pair <short, short>, pair<bool ,int >>> q;

bool dir[1001][1001];
bool check[1001][1001][2];
long long minn = -1;
int x, y;
void qpush(int x, int y, int dd, int flag, int count) {
	if (dd == 1)
		flag = 1;
	if (x + 1 < N && dir[x + 1][y] == dd && check[x + 1][y][flag] == false) {
		q.push(make_pair(make_pair(x + 1, y), make_pair(flag, count + 1)));
		check[x + 1][y][flag] = true;
	}

	if (y + 1 < M && dir[x][y + 1] == dd && check[x][y + 1][flag] == false) {
		q.push(make_pair(make_pair(x, y + 1), make_pair(flag, count + 1)));
		check[x][y + 1][flag] = true;
	}

	if (x - 1 >= 0 && dir[x - 1][y] == dd && check[x - 1][y][flag] == false) {
		q.push(make_pair(make_pair(x - 1, y), make_pair(flag, count + 1)));
		check[x - 1][y][flag] = true;
	}

	if (y - 1 >= 0 && dir[x][y - 1] == dd && check[x][y - 1][flag] == false) {
		q.push(make_pair(make_pair(x, y - 1), make_pair(flag, count + 1)));
		check[x][y - 1][flag] = true;
	}

	
}


int BFS(int x, int y) {
	q.push(make_pair(make_pair(x, y) ,make_pair(false, 1)));
	check[x][y][0]= true;
	while (!q.empty()) {
		int ss = q.size();
		for (int i = 0; i < ss; i++) {
			x = q.front().first.first;
			y = q.front().first.second;
			bool flag = q.front().second.first;
			int count = q.front().second.second;
			q.pop();
			if (x == N - 1 && y == M - 1)
				return count;
			if (flag == false) {
				qpush(x, y, 1, flag, count);
			}
			qpush(x, y, 0, flag, count);
		}


	}

	return -1;
}

int main() {
	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &dir[i][j]);
		
		}
	}


	cout << BFS(0, 0);


}