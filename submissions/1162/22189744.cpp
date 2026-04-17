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

struct cmp {
	bool operator() (pair <int, int> a, pair <int, int> b) {
		return a.second > b.second;
	}
};
vector <pair <int,int>> graph[10001];


int N, M, K;



long long dijkstra() {

	priority_queue <pair <int, long long>, vector <pair <int, long long>>, cmp> q;

	dp[1][0] = 0;
	check[1] = true;

	for (pair <int,int> next: graph[1]) { // 초기 작업
		q.push(next);
		dp[next.first][0] = next.second;
		dp[next.first][1] = 0;
	}

	while (q.size()) {
		pair <int, long long> front = q.top(); // 제일 가중치가 적은 간선부터 선택
		q.pop();

		for (pair <int, int> next : graph[front.first]) {
			if (check[next.first] == false) {
				
				for (int i = 0; i <= K; i++) {
					if (dp[front.first][i] != -1) {
						if (dp[next.first][i] == -1)
							dp[next.first][i] = dp[front.first][i] + next.second;
						else
							dp[next.first][i] = min(dp[next.first][i], dp[front.first][i] + next.second);
						if (i + 1 <= K)
							if (dp[next.first][i + 1] == -1)
								dp[next.first][i + 1] = dp[front.first][i];
							else
								dp[next.first][i + 1] = min(dp[next.first][i + 1], dp[front.first][i]);
					}
				}
				check[next.first] = true;
				q.push({ next.first, dp[next.first][0] });
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

	memset(dp, -1, sizeof(dp));
	cout << dijkstra();
	//system("Pause");
}