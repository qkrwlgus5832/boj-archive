#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int graph[26][26];
bool check[26][26];
int dir[4][2] = { { 0,1 }, {0,-1}, {1,0}, {-1,0} };
queue <pair <int,int>> q;
vector <int> v;

bool chk(int x1, int y1) {
	if (x1 < 0 || y1 < 0 || x1 >= N || y1 >= N)
		return false;
	if (check[x1][y1] == false && graph[x1][y1] == 1) {
		q.push(make_pair(x1, y1));
		check[x1][y1] = true;
		return true;
	}
	return false;
}
int BFS(int i, int j) {
	q.push(make_pair(i, j));
	check[i][j] = true;
	int count = 1;
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x2 =  x1 + dir[i][0];
			int y2=  y1 + dir[i][1];
			if (chk(x2, y2))
				count++;
		}

	}
	return count;

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}


	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == false && graph[i][j] == 1) {
				v.push_back(BFS(i, j));
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

}