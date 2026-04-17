#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

long long dp[10001][21];
int bfscheck[10001];

vector <pair <int,int>> graph[10001];
int N, M, K;

long long BFS(int x) {
	queue <int> q;
	q.push(x);

	dp[1][0] = 0;
	bfscheck[1] = 1;

	int length = 1;


	while (q.size()) {
		int s = q.size();

		for (int qs = 0; qs < s; qs++) {
			int front = q.front();
			q.pop();

			for (pair <int, int> edge : graph[front]) {
				int next = edge.first;
				int time = edge.second;

				if (bfscheck[next] !=0 && bfscheck[next] < length) // 방문을 이미 했기는 했고, 그 전 레벨에서 방문했다면
					continue; // 최단경로를 구해야하므로 continue

				bfscheck[next] = length;
				q.push(next);
		

				for (int i = 0; i <= K; i++) {
					if (dp[front][i] == -1) 
						break;

					if (dp[next][i] == -1) {
						dp[next][i] = dp[front][i] + time;
					}
					else
						dp[next][i] = min(dp[next][i], dp[front][i] + time);


					if (i + 1 <= K) {
						if (dp[next][i + 1] == -1)
							dp[next][i + 1] = dp[front][i];
						else
							dp[next][i + 1] = min(dp[next][i + 1], dp[front][i]);
					}
				
				}
			
			}
		}
		length++;
	}
	
	long long result = LLONG_MAX;

	for (int i = 0; i <= K; i++) {
		if (result != -1)
			result = min(result, dp[N][i]);
	}

	return result;
}

int main() {

	cin >> N >> M >> K;

	int start, end,  time;

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &start, &end, &time);
		graph[start].push_back({ end,time });
		graph[end].push_back({ start, time });
	}

	memset(dp, -1, sizeof(dp));
	cout << BFS(1);
	//system("Pause");
}