#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

vector <int> graph[1000001];
bool bfsCheck[1000001];

int countCheck[2];

int BFS(int i) {
	queue <int> q;
	q.push(i);
	bfsCheck[i] = true;

	int length = 0;


	while (q.size()) {
		int s = q.size();
		countCheck[length % 2] += s;
		for (int qs = 0; qs < s; qs++) {
			
			int front = q.front();
			q.pop();

			for (int next : graph[front]) {
				if (bfsCheck[next] == false) {
					bfsCheck[next] = true;
					q.push(next);
				}
			}

		}
	
		length++;
	}

	return min(countCheck[0], countCheck[1]);
}


int main() {
	cin >> N;

	int u, v;

	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);

	}

	cout << BFS(1);
	//system("Pause");
}