#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

bool issosu(int x) {
	for (int i = 2; i <= x / 2; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

pair < pair <int, int>, pair <int, int>> geteachdigit(int x) {
	int d1 = x / 1000;
	int d2 = x % 1000 / 100;
	int d3 = x % 1000 % 100 / 10;
	int d4 = x % 1000 % 100 % 10;

	return make_pair(make_pair(d1, d2), make_pair(d3, d4));
}

int getoriginnumber(pair <int, int> a, pair <int, int> b) {
	return a.first * 1000 + a.second * 100 + b.first * 10 + b.second;
}

void queuepush(pair < pair <int, int>, pair <int, int>> tmp, queue <int>& q, bool check[]) {
	int candidate = getoriginnumber(tmp.first, tmp.second);
	if (check[candidate] == false && issosu(candidate) == true) {
		check[candidate] = true;
		q.push(candidate);
	}
}
int BFS(int a, int b) {
	queue <int> q;
	bool check[10000] = { false, };
	q.push(a);
	check[a] = true;
	int time = 0;
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int front = q.front();
			q.pop();
			pair < pair <int, int>, pair <int, int>> tmp = geteachdigit(front);
			if (front == b)
				return time;
			for (int i = 1; i <= 9; i++) {
				tmp.first.first = i;
				queuepush(tmp, q, check);
			}
			tmp = geteachdigit(front);
			for (int i = 0; i <= 9; i++) {
				tmp.first.second = i;
				queuepush(tmp, q, check);
			}
			tmp = geteachdigit(front);
			for (int i = 0; i <= 9; i++) {
				tmp.second.first = i;
				queuepush(tmp, q, check);
			}
			tmp = geteachdigit(front);
			for (int i = 0; i <= 9; i++) {
				tmp.second.second = i;
				queuepush(tmp, q, check);

			}
		}
		time++;
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	int a, b;
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &a, &b);
		int result = BFS(a, b);
		if (result == -1) {
			printf("Impossible\n");
		}
		else {
			printf("%d\n", result);
		}
	}
	//system("Pause");
}