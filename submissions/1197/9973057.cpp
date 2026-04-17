#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int V, E;
int A, B, C;
vector <pair <int, pair <int, int>>> v;
int unionfind[10001];

int find(int x) {
	if (unionfind[x] < 0)
		return x;
	unionfind[x] = find(unionfind[x]);
	return unionfind[x];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	
	unionfind[b] = a;

}

int main() {
	cin >> V >> E;
	memset(unionfind, -1, sizeof(unionfind));
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &A, &B, &C);
		v.push_back(make_pair(C, make_pair(A, B)));
	}

	sort(v.begin(), v.end());




	int dd = 0;
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		if (find(v[i].second.first) != find(v[i].second.second)) {
			merge(v[i].second.first, v[i].second.second);
			dd++;
			result += v[i].first;
		}
		if (dd == V - 1)
			break;

	}
	cout << result;

}