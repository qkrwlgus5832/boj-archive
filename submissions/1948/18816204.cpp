#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;
vector <pair <int,int>> graph[10001];
vector <pair <int, int>> backgraph[10001];

int maxTime[10001];

int depth[10001];

bool check[10001][10001];

int resultcount = 0;

int topologicalSort(int startCity, int arriveCity) {
	queue <int> q;

	q.push(startCity);

	while (q.size()) {
		int front = q.front();
		q.pop();
		for (pair <int, int> node : graph[front]) {
			if (maxTime[node.first] < maxTime[front] + node.second) {
				maxTime[node.first] =  maxTime[front] + node.second;
			}

			if (--depth[node.first] == 0) {
				q.push(node.first);
			}
		}
	}

	return maxTime[arriveCity];
}

void DFS(int current, int end, int cost) {
	if (current == end) {
		return;
	}
	for (pair <int, int> node : backgraph[current]) {
		if (cost - node.second == maxTime[node.first]) {
			if (check[current][node.first] == false) {
				check[current][node.first] = true;
				resultcount++;
				DFS(node.first, end, cost - node.second);
			}

		}
	}
}

int main() {
	cin >> n;
	cin >> m;

	int a, b, c;

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b,c });
		backgraph[b].push_back({ a,c });
		depth[b]++;
	}

	int startCity, arriveCity;

	cin >> startCity >> arriveCity;

	int resultcost = topologicalSort(startCity, arriveCity);

	cout << resultcost << endl;


	DFS(arriveCity, startCity, resultcost);

	cout << resultcount;

	//system("Pause");

}