#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

vector <int> graph[501];
int depth[501];

int minTime[501];
int buildTime[501];

void topologicalSort() {
	queue <int> q;
	for (int i = 1; i <= N; i++) {
		if (depth[i] == 0) {
			q.push(i);
			minTime[i] = buildTime[i];
		}
	}
	while (q.size()) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < graph[front].size(); i++) {
			if (--depth[graph[front][i]] == 0) {
				q.push(graph[front][i]);
				minTime[graph[front][i]] = max(minTime[graph[front][i]], minTime[front] + buildTime[graph[front][i]]);
			}
		}
	}
}

int main() {
	int time;
	int tmp;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &time);
		buildTime[i] = time;
		while (1) {
			scanf("%d", &tmp);
			if (tmp == -1) {
				break;
			}
			graph[tmp].push_back(i);
			depth[i]++;
		}
	}
	topologicalSort();
	for (int i = 1; i <= N; i++) {
		printf("%d\n", minTime[i]);
	}
	//system("Pause");
}