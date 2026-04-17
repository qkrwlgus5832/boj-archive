#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int N;
int M;

priority_queue<int, vector <int>, greater<int>> minq[32001];
bool check[32001];
vector <int> result;

void BFS(int x) {
	queue <int> bfsq;
	stack <int> st;
	st.push(x);
	bfsq.push(x);
	check[x] = true;
	while (!bfsq.empty()) {
		int top = bfsq.front();
		bfsq.pop();
		bool flag = false;

		for (int i = 0; i < minq[top].size(); i++) {
			if (check[minq[top].top()] == false) {
				st.push(minq[top].top());
				bfsq.push(minq[top].top());
				check[minq[top].top()] = true;
				flag = true;
			}
		}

		if (flag == false)
			break;
	}
	
	while (st.size()) {
		result.push_back(st.top());
		st.pop();
	}
}

int main() {
	cin >> N >> M;
	int A, B;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &A, &B);
		minq[B].push(A);
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == false)
			BFS(i);
	}
	for (int i = 0; i < result.size(); i++)
		printf("%d ", result[i]);
	//system("Pause");
}