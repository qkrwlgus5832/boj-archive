#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int graph[801][801];
int unionFind[5];

int N, E;

void floid() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

struct edge {
	int start;
	int end;
	int distance;
};


void merge(int a, int b) {
	unionFind[a] = b;
}

int find(int a) {
	if (unionFind[a] == -1)
		return a;

	return find(unionFind[a]);
}

int main() {

	cin >> N >> E;


	int a, b, c;

	vector <int> v;
	

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = c;
		graph[b][a] = c;
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == 0)
				graph[i][j] = INT_MAX;
		}
	}

	floid();

	v.push_back(1);
	int v1, v2;
	cin >> v1 >> v2;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(N);


	vector <edge> edges;

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			int distance = graph[v[i]][v[j]];
			if (distance != INT_MAX) {
				edges.push_back({ v[i], v[j], distance });
			}
		}
	}

	sort(edges.begin(), edges.end(), [](const edge&a, const edge&b) {
		return a.distance < b.distance;
	});

	memset(unionFind, -1, sizeof(unionFind));
	int edgeCount = 0;
	int result = 0;

	for (auto edge : edges) {
		int edgeStartParent = find(edge.start);
		int edgeEndParent = find(edge.end);

		if (edgeStartParent != edgeEndParent) {
			merge(edgeStartParent, edgeEndParent);
			edgeCount++;
			result += edge.distance;
		}
		if (edgeCount == 3) {
			cout << result;
			return 0;
		}

	}
	cout << -1;

}