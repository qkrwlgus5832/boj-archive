#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int N, M;

vector <pair <int, int>> home;
vector <pair <int, int>> chicken;


int graph[51][51];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int result = INT_MAX;

int BFS(int i, int j) {
	bool check[51][51] = { false, };
	queue <pair <int, int>> q;
	q.push(make_pair(i, j));
	check[i][j] = true;

	int count = 0;

	while (q.size()) {
		int s = q.size();
		for (int ts = 0; ts < s; ts++) {
			pair <int, int> front = q.front();
			q.pop();

			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.first + dir[i1][0];
				int nj = front.second + dir[i1][1];

				if (graph[ni][nj] == 2) {
					return count + 1;
				}
				if (ni < 0 || nj < 0 || ni >= N || nj >= N)
					continue;

				if (check[ni][nj] == false) {
					check[ni][nj] = true;
					q.push(make_pair(ni, nj));
				}
			}
		}
		count++;
	}
	return INT_MAX;
}
int calculate() {
	int length = 0;
	for (int i = 0; i < home.size(); i++) {
		length += BFS(home[i].first, home[i].second);
	}
	return length;
}
void recursion(int i, int count) {
	if (count == chicken.size() - M) {
		result= min(result,calculate());
		return;
	}
	for (int index = i; index < chicken.size(); index++) {
		graph[chicken[index].first][chicken[index].second] = 0;
		recursion(index + 1, count + 1);
		graph[chicken[index].first][chicken[index].second] = 2;
	}
}

int main() {
	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 1) {
				home.push_back(make_pair(i, j));
			}
			else if (graph[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	recursion(0, 0);
	cout << result;
	//system("Pause");
}
