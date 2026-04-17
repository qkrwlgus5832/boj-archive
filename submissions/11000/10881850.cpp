#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int N;
vector <pair <int, int>> v;
priority_queue<int, vector <int>, greater<int>> pq;

int main() {
	scanf("%d", &N);
	int tmp1, tmp2;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &tmp1, &tmp2);
		v.push_back(make_pair(tmp1, tmp2));
	}

	sort(v.begin(), v.end());

	int index = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			pq.push(v[i].second);
			continue;
		}
		int tmp = pq.top();
		if (tmp <= v[i].first) {
			pq.pop();
			pq.push(v[i].second);

		}
		else {
			pq.push(v[i].second);
		}
	}
	cout << pq.size();

}