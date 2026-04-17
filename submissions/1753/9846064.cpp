#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <algorithm>
using namespace std;


vector <vector<pair<int, int>> > graph;


int G[20001];
int V, E;
int K;


void dikjstra(int i) {
	priority_queue <pair<int, int>, vector <pair< int, int>>, greater <pair<int, int>>> q;
	bool check[20001] = { false, };
	check[i] = true;
	G[i] = 0;
	q.push(make_pair(0,i));

	while (!q.empty()) {
		int dis = q.top().first;
		int v1 = q.top().second;
		q.pop();
		check[v1] = true;
		for (int i1 = 0; i1 < graph[v1].size(); i1++) {
			if (check[graph[v1][i1].first] == false) {
				G[graph[v1][i1].first] = min(G[graph[v1][i1].first], dis + graph[v1][i1].second);
				q.push(make_pair(dis + graph[v1][i1].second, graph[v1][i1].first));
			}

		}
	}



}


int main() {
	cin >> V >> E;
	cin >> K;
	int u, v, w;

	graph.resize(20001);


	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(make_pair(v, w));
	}

	memset(G, 1, sizeof(G));
	dikjstra(K);

	for (int i = 1; i <= V; i++) {
		if (G[i] > 10)
			printf("INF");
		else
		printf("%d\n", G[i]);

	}

}