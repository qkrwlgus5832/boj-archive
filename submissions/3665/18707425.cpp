#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

int n;

bool graph[501][501];
int depth[501];

pair <int, vector<int>> topologicalSort(int n) {
	queue <int> q;
	vector <int> result;
	for (int i = 1; i <= n; i++) {
		if (depth[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {

		int s = q.size();
		if (s > 1)
			return { -1, vector<int>() };
		int front = q.front();
		result.push_back(front);
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (graph[front][i] == true) {
				if (--depth[i] == 0)
					q.push(i);
			}
		}

	}
	if (result.size() == n) {
		return { 1, result };
	}
	return { 0 , vector <int>() };
}
int main() {
	int T;
	cin >> T;
	int n;
	int beforeNode;
	int afterNode;
	int m;
	for (int t = 0; t < T; t++) {
		memset(graph, false, sizeof(graph));
		memset(depth, false, sizeof(depth));
		vector <int> v;
		scanf("%d", &n);
	
		int order;
		for (int i = 0; i < n; i++) {
			scanf("%d", &order);
			v.push_back(order);
		}

		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				graph[v[i]][v[j]] = true;
				depth[v[j]]++;
			}
		}
		scanf("%d", &m);

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &beforeNode, &afterNode);
			if (graph[beforeNode][afterNode] == true) {
				swap(beforeNode, afterNode);
			}
			graph[afterNode][beforeNode] = false;
			depth[beforeNode]--;
			graph[beforeNode][afterNode] = true;
			depth[afterNode]++;
		}
		pair <int, vector<int>> result = topologicalSort(n);

		if (result.first == 1) {
			for (int i = 0; i < result.second.size(); i++) {
				printf("%d ", result.second[i]);
			}
		}
		else if (result.first == -1) {
			printf("?");
		}
		else if (result.first == 0) {
			printf("IMPOSSIBLE");
		}
		printf("\n");
	}
	//system("Pause");
}