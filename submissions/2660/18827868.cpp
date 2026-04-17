#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> graph[51];

int n;
int BFS(int x) {
	queue <int> q;

	bool check[51] = { false, };

	q.push(x);
	check[x] = true;
	int depth = 0;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			int front = q.front();
			q.pop();

			for (auto item : graph[front]) {
				if (check[item] == false) {
					check[item] = true;
					q.push(item);
				}
			}
		}
		depth++;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == false)
			return -1;
	}
	return depth -1;
}
int main() {

	cin >> n;

	int a, b;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == -1 && b == -1) {
			break;
		}
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector <int> result;
	int score = INT_MAX;

	for (int i = 1; i <= n; i++) {
		int tmp = BFS(i);
		if (tmp != -1) {
			if (tmp == score) {
				result.push_back(i);
			}
			else if (tmp < score) {
				result.clear();
				result.push_back(i);
				score = tmp;
			}
		}
	}

	cout << score << " " << result.size() << endl;
	for (auto i : result) {
		printf("%d ", i);
	}
	//system("Pause");
}