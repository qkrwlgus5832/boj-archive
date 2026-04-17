#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>

using namespace std;

int N, K;



int depth[1001];

int time[1001];

int timecheck[1001];

int topologicalSort(int W, vector <int> graph[1001]) {
	queue <int> q;

	for (int i = 1; i <= N; i++) {
		if (depth[i] == 0) {
			q.push(i);
			timecheck[i] = time[i];
		}
	}

	while (q.size()) {
		int front = q.front();
		q.pop();
		if (front == W) {
			return timecheck[W];
		}
		for (int i = 0; i < graph[front].size(); i++) {
			timecheck[graph[front][i]] = max(timecheck[graph[front][i]],  timecheck[front] + time[graph[front][i]]);
			if (--depth[graph[front][i]] == 0) {
				q.push(graph[front][i]);
				
			}
		}
	}
}

int main() {
	int T;
	
	cin >> T;
	for (int t = 0; t < T; t++) {

		vector <int> graph[1001];

		scanf("%d %d", &N, &K);

		memset(time, 0, sizeof(time));
		memset(timecheck, 0, sizeof(timecheck));
		memset(depth, 0, sizeof(depth));

		for (int i = 1; i <= N; i++) {
			scanf("%d", &time[i]);
		}

		int a, b;
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			depth[b]++;
		}

		int W;
		scanf("%d", &W);
		printf("%d\n", topologicalSort(W, graph));

	}

	//system("Pause");
}