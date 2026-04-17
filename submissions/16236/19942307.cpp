#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N;

int graph[21][21];
pair <int, int> babyshark;
int currentsize = 2;

int dir[4][2] = { {-1,0}, {0 ,-1}, {1,0},{0,1} };

int BFS() {
	bool check[21][21] = { false, };

	queue <pair <int, int>> q;
	q.push(make_pair(babyshark.first, babyshark.second));
	check[babyshark.first][babyshark.second] = true;
	int length = 0;

	vector <pair <int,int>> tmp;

	bool flag = false;

	while (q.size()) {
		int s = q.size();
		for (int ts = 0; ts < s; ts++) {
			pair <int, int> front = q.front();
			q.pop();
			
			if (length != 0 && graph[front.first][front.second] > 0 && currentsize > graph[front.first][front.second]) {
				flag = true;
				tmp.push_back(make_pair(front.first, front.second));
			}
			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.first + dir[i1][0];
				int nj = front.second + dir[i1][1];
				
				if (ni < 0 || nj < 0 || ni >= N || nj >= N)
					continue;
				if (check[ni][nj] == false && graph[ni][nj] <= currentsize) {
					check[ni][nj] = true;
					q.push(make_pair(ni, nj));
					

				}
			}
		}
		if (flag == true) {
			int i1 = tmp[0].first;
			int j1 = tmp[0].second;
			for (int i = 1; i < tmp.size(); i++) {
				if (tmp[i].first < i1) {
					i1 = tmp[i].first;
					j1 = tmp[i].second;
				}
				else if (tmp[i].first == i1 && tmp[i].second < j1) {
					i1 = tmp[i].first;
					j1 = tmp[i].second;
				}
			}
			babyshark.first = i1;
			babyshark.second = j1;
			graph[i1][j1] = 0;
			return length;
		}
		length++;
	}

	return -1;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 9) {
				babyshark.first = i;
				babyshark.second = j;
				graph[i][j] = 0;
			}
		}
	}
	int time = 0;
	int count = 0;
	while (1) {
		int result = BFS();
		if (result == -1)
			break;
		else {
			time += result;
			count++;
			if (count == currentsize) {
				count = 0;
				currentsize++;
			}
		}
	}
	cout << time;
	//system("Pause");
}