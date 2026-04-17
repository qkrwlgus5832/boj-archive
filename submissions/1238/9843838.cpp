#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <functional>
#include <queue>

using namespace std;

int dd[1001][1001];

vector <vector <pair<int,int>>> graph;
int N, M, X;

void Dijkstra(int i) {
	dd[i][i] = 0;
	bool check[1001] = { false, };
	priority_queue <pair <int, int>, vector<pair<int, int>>, greater <pair <int, int> >> q;
	check[i] = true;
	q.push(make_pair(0,i));

	while (!q.empty()) {
		int dis = q.top().first;
		int v1 = q.top().second;
		q.pop();
		check[v1] = true;
		for (int i1 = 0; i1 < graph[v1].size(); i1++) {
			if (check[graph[v1][i1].first] == false) {
				dd[i][graph[v1][i1].first] = min(dd[i][graph[v1][i1].first], dis + graph[v1][i1].second);
				q.push(make_pair(dis + graph[v1][i1].second, graph[v1][i1].first));
				

			}

		}
	}

}



int main() {
	cin >> N >> M >> X;

	int start, end, T;
	graph.resize(1001);


	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &start, &end, &T);
		graph[start].push_back(make_pair(end,T));
	}


	memset(dd, 1, sizeof(dd));

	for (int i = 1; i <= N; i++)
		Dijkstra(i);

	int result = 0;
	for (int i = 1; i <= N; i++) {
		if (i == X)
			continue;
		result = max(result, dd[i][X] + dd[X][i]);

	}
	cout << result;


}