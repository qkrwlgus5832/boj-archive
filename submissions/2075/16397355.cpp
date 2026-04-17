#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <functional>
#include <limits.h>
using namespace std;

priority_queue <int, vector<int>, greater<int>> q;

//int startindex[1501];

int main() {
	int N;
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);
			q.push(tmp);
			if (q.size() == N + 1) {
				q.pop();
			}
		}
	}

	cout << q.top();

	//system("Pause");
}