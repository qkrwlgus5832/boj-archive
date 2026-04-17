#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector <int> graph[32001];
int depth[32001];
bool check[32001];
vector <int> result;

void topologicalSort() {
	queue <int> q;

	for (int i = 1; i <= N; i++) {
		if (depth[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		int front = q.front();

		if (check[front] == false) {
			check[front] = true;
			result.push_back(front);
		}
		q.pop();
		for (int i = 0; i < graph[front].size(); i++) {
			if (--depth[graph[front][i]] == 0) {
				q.push(graph[front][i]);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	int a, b;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		depth[b]++;
	}

	topologicalSort();

	for (int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}
	//system("Pause");
}