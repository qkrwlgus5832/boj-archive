#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

vector  <pair < int, pair <int, int>> > v;
int unionfind[1001];
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
	int N;
	int M;
	cin >> N;
	cin >> M;
	int a, b, c;
	memset(unionfind, -1, sizeof(unionfind));
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v.push_back(make_pair(c, make_pair(a, b)));
	}

	int count = 0;
	int result = 0;
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++)
	{
		if (find(v[i].second.first) != find(v[i].second.second)) {
			merge(v[i].second.first, v[i].second.second);
			count++;
			result += v[i].first;
		}
		if (count == N - 1) {
			printf("%d", result);
			break;
		}


	}

}