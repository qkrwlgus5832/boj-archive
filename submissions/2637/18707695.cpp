#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N;
int depth[101];
vector <pair <int,int>> needCount[101];
vector <int> graph[101];
int check[101];
int dp[101][101];
vector <int> resultBackup;

void topologicalSort() {
	queue <int> q;

	for (int i = 1; i <= N; i++) {
		if (check[i] > 0  && depth[i] == 0) {
			q.push(i);
			dp[i][i] = 1;
			resultBackup.push_back(i);
		}
	}
	while (q.size()) {
		int front = q.front();
		q.pop();
		for (pair <int, int> item : needCount[front]) {
			for (int i = 1; i <= N; i++) {
				dp[front][i] += dp[item.first][i] * item.second;
			}
		}

		for (int item : graph[front]) {
			if (--depth[item] == 0) {
				q.push(item);

			}
		}
	}
}

int main() {
	cin >> N;
	int M;
	cin >> M;

	int X, Y, K;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &X, &Y, &K);
		depth[X]++;
		graph[Y].push_back(X);
		check[Y] = 1;
		needCount[X].push_back({ Y,K });
	}

	topologicalSort();

	for (int item : resultBackup) {
		printf("%d %d\n", item, dp[N][item]);
	}
	//system("Pause");
}