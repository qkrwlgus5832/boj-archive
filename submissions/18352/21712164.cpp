#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, X;

vector <vector <int>> graph;
vector <int> result;

void BFS() {
	bool check[300001] = { false, };

	int length = 0;

	queue <int> q;
	q.push(X);
	check[X] = true;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			int front = q.front();
			q.pop();

			for (int tmp : graph[front]) {
				if (check[tmp] == false) {
					check[tmp] = true;
					q.push(tmp);
				}
			}
		}
		length++;
		if (length == K) {
			break;
		}
	}
	if (q.size()) {
		while (q.size()) {
			result.push_back(q.front());
			q.pop();
		}
	}
	else {
		result.push_back(-1);
	}
}
int main() {
	cin >> N >> M >> K >> X;

	graph.resize(N + 1);	

	int A, B;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &A, &B);
		graph[A].push_back(B);
	}

	BFS();

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		printf("%d\n", result[i]);
	}
	//system("Pause");
}
