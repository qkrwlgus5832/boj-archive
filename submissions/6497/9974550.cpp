#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
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
	int m, n;
	int x, y, z;



	while (1) {
		int dd = 0;
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0)
			return 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &z);
			dd += z;
			v.push_back(make_pair(z, make_pair(x, y)));

		}
		memset(unionfind, -1, sizeof(unionfind));
		sort(v.begin(), v.end());

		int count = 0;
		int result = 0;
		for (int i = 0; i < v.size(); i++) {
			if (find(v[i].second.first) != find(v[i].second.second)) {
				merge(v[i].second.first, v[i].second.second);
				count++;
				result = result + v[i].first;

			}
			if (count == m - 1)
				break;
		}

		printf("%d\n", dd - result);
		v.clear();
	}


}