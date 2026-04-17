#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector <int> graph[1001];
vector <int> result;
int depth[1001];

bool check[1001];

void topologicalSort() {
	queue <int> q;

	for (int i = 1; i <= N; i++) {
		if (depth[i] == 0) {
			q.push(i);
		}
	}

	while (q.size()) {
		int front = q.front();
		q.pop();
		if (check[front] == false) {
			check[front] = true;
			result.push_back(front);
		}
		for (int i = 0; i < graph[front].size(); i++) {
			if (--depth[graph[front][i]] == 0) {
				q.push(graph[front][i]);
			}
		}
	}
}

int main() {
	cin >> N >> M;


	int number;
	int prevSinger;
	int nextSinger;

	for (int i = 0; i < M; i++) {
		scanf("%d", &number);
		scanf("%d", &prevSinger);
		for (int j = 0; j < number - 1; j++) {
			scanf("%d", &nextSinger);
			graph[prevSinger].push_back(nextSinger);
			depth[nextSinger]++;
			prevSinger = nextSinger;
		}
	}
	topologicalSort();
	if (result.size() == N) {
		for (int i = 0; i < result.size(); i++) {
			printf("%d\n", result[i]);
		}
	}
	else {
		printf("0");
	}
	//system("Pause");
}