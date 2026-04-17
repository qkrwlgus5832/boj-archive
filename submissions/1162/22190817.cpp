#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <limits.h>

using namespace std;

long long dp[10001][21];
int check[10001];
bool dpCheck[10001][21];



struct node {
	int end;
	int count;
	long long time;
};


struct cmp {
	bool operator() (const node& a, const node& b) {
		return a.time > b.time;
	}
};
vector <pair <int,int>> graph[10001];


int N, M, K;


long long dijkstra() {

	priority_queue <node, vector <node>, cmp> q;

	dp[1][0] = 0;
	check[1] = true;
	q.push({ 1, 0, 0 });

	while (q.size()) {
		node front = q.top();
		q.pop();
		dpCheck[front.end][front.count] = true;

		for (pair <int, int> next : graph[front.end]) { 
			if (dpCheck[next.first][front.count] == false) {
				dp[next.first][front.count] = min(dp[next.first][front.count], dp[front.end][front.count] + next.second);
				q.push({ next.first, front.count , front.time + next.second });
			}
			if (front.count + 1 <= K && dpCheck[next.first][front.count + 1] == false) {
				dp[next.first][front.count + 1] = min(dp[next.first][front.count + 1], dp[front.end][front.count]);
				q.push({ next.first, front.count + 1 , front.time});
			}

		}

	}
	
	long long distance = LLONG_MAX;

	for (int i = 0; i <= K; i++) {
		if (dp[N][i] != -1)
			distance = min(distance, dp[N][i]);
	}
	return distance;
}




int main() {

	cin >> N >> M >> K;

	int start, end,  time;

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &start, &end, &time);
		graph[start].push_back({ end, time });
		graph[end].push_back({ start, time });
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j] = INT_MAX;
		}
	}


	cout << dijkstra();
	//system("Pause");
}