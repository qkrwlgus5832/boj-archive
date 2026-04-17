#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
#include <alg.h>
using namespace std;
priority_queue < pair <int, pair <int, int >>> q;
int unionfind[100001];

int N, M;


int find(int x) {
	if (unionfind[x] < 0)
		return x;
	
	unionfind[x] = find(unionfind[x]);
	return unionfind[x];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	else if (a > b)
		unionfind[a] = b;
	else if (a < b)
		unionfind[b] = a;
}
int main() {
	cin >> N >> M;
	int A, B, C;
	memset(unionfind, -1, sizeof(unionfind));

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B ,&C);
		if (A > B) 
			swap(A, B);
		q.push(make_pair(C, make_pair(A, B)));

	}
	int start, finish;
	cin >> start >> finish;

	while (1) {
		merge(q.top().second.first, q.top().second.second);
		if (find(start) == find(finish))
			break;
		q.pop();
	}

	cout << q.top().first;
}