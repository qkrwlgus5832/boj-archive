#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>


using namespace std;

int N;
int M;

priority_queue<int, vector <int>, greater<int>> minq;
int depth[32001];
vector <int> v[32001];
vector <int> result;
void BFS() {
	for (int i = 1; i <= N; i++) {
		if (depth[i] == 0) {
			minq.push(i);
		}
	}

	while (minq.size()) {
		int top = minq.top();
		minq.pop();
		result.push_back(top);

		for (int i = 0; i < v[top].size(); i++) {
			if (depth[v[top][i]] > 0) {
				depth[v[top][i]]--;
				if (depth[v[top][i]] == 0)
					minq.push(v[top][i]);
			}

		}
	}
}


int main() {
	cin >> N >> M;
	int A, B;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &A, &B);
		v[A].push_back(B);
		depth[B]++;
	}
	
	BFS();

	for (int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}
	//system("Pause");
}