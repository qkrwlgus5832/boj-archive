#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int T;

priority_queue <pair <long long, int>> q;

int main() {
	cin >> N >> T;
	int w, p;

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &w, &p);
		q.push(make_pair(w + (long long ) p * (T - 1), p));
	}

	long long result = 0;

	for (int i = 0; i < N; i++) {
		long long tmp = (i * q.top().second);
		result += q.top().first - tmp;
		q.pop();
	}
	cout << result;
	//system("Pause");
}