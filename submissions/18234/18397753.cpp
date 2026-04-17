#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int T;

priority_queue <pair <int, int>> q;

int main() {
	cin >> N >> T;
	int w, p;

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &w, &p);
		q.push(make_pair(p, w));
	}
	
	long long result = 0;

	for (int i = 0; i < N; i++) {
		result += (long long) q.top().first * (T - 1 - i) + q.top().second;
		q.pop();
	}

	cout << result;
	//system("Pause");
}