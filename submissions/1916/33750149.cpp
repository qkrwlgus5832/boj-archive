#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <functional>
#include <memory.h>
#include <vector>
#include <queue>
#define t_max 1000000000
using namespace std;

vector <vector <pair <int, int > >> graph;

int n;
int m;
int G[1001];

void dikstra(int i) {
	priority_queue <pair<int, int>, vector <pair< int, int>>, greater <pair<int, int>>> q;
	bool check[1001] = { false, };
	check[i] = true;
	G[i] = 0;
	q.push(make_pair(0, i));

	while (!q.empty()) {
		int dis = q.top().first;
		int v1 = q.top().second;
		q.pop();
		check[v1] = true;

		if (G[v1] < dis) {
			continue;
		}
		for (int i1 = 0; i1 < graph[v1].size(); i1++) {
			if (check[graph[v1][i1].first] == false) {
				if (G[graph[v1][i1].first] > dis + graph[v1][i1].second) {
					G[graph[v1][i1].first] = dis + graph[v1][i1].second;
					q.push(make_pair(dis + graph[v1][i1].second, graph[v1][i1].first));

				}
			}
		}
	}
}


int main() {
	cin >> n;
	cin >> m;

	graph.resize(1001);
	int u, v, w;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(make_pair(v, w));
	}
	int start, end;
	cin >> start >> end;

	for (int i = 1; i <= n; i++)
		G[i] = t_max;


	dikstra(start);

	cout << G[end];
	//system("Pause");
}