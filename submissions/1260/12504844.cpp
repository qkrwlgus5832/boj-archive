#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>
using namespace std;

bool check[1001];
bool graph[1001][1001];

vector <int> result;
void BFS(int V) {
	queue <int> q;
	q.push(V);
	result.push_back(V);
	check[V] = true;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 1; i <= 1000; i++) {
			if (graph[i][tmp] == true && check[i] == false) {
				check[i] = true;
				q.push(i);
				result.push_back(i);

			}
		}
	}
}

void DFS(int V) {
	for (int i = 1; i <= 1000; i++) {
		if (graph[i][V] == true && check[i] == false) {
			check[i] = true;
			result.push_back(i);
			DFS(i);
		}
	}
}

int main() {
	int N, M, V;

	cin >> N >> M >> V;
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = true;
		graph[b][a] = true;
	}

	check[V] = true;
	result.push_back(V);
	DFS(V);
	for (int i = 0; i < result.size(); i++) {
		if (i == result.size() - 1)
			printf("%d\n", result[i]);
		else
			printf("%d ", result[i]);
	}
	result.clear();
	memset(check, 0, sizeof(check));

	BFS(V);
	for (int i = 0; i < result.size(); i++) {
		if (i == result.size() - 1)
			printf("%d", result[i]);
		else
			printf("%d ", result[i]);

	}

}
