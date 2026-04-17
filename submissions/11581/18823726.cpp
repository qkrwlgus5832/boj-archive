#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int depth[101];
vector <int> graph[101];

string topologicalSort(int N) {
	queue <int> q;
	for (int i = 1; i <= N; i++) {
		if (depth[i] == 0) {
			q.push(i);
		}
	}

	int count = 0;

	while (q.size()) {
		int front = q.front();
		q.pop();
		if (front == N) {
			return "NO CYCLE";
		}
		count++;
		for (int node : graph[front]) {
			if (--depth[node] == 0) {
				q.push(node);
			
			}
		}
	}

	return "CYCLE";
}

int main() {
	int N;
	cin >> N;

	int count;
	int number;
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d", &count);
		for (int j = 0; j < count; j++) {
			scanf("%d", &number);
			graph[i].push_back(number);
			depth[number]++;
		}
	}
	
	cout << topologicalSort(N);
	//system("Pause");

}