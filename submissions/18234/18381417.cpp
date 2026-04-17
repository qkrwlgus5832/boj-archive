#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, T;

//vector <pair <int, int>> v;

priority_queue <pair <long long, int>> q;

int main() {
	cin >> N >> T;
	int w, p;

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &w, &p);
		//v.push_back(make_pair(w, p));
		q.push(make_pair(w + p * (T - 1), p));
	}
	long long result = 0;
	for (int i = 0; i < N; i++) {
		result += q.top().first - (i * q.top().second);
		q.pop();
	}
	cout << result;
	//system("Pause");
}