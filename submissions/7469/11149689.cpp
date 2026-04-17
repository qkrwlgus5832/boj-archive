#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;
vector <pair <int, int>> v;
int main() {
	cin >> n >> m;
	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		v.push_back(make_pair(tmp, i + 1));
	}

	sort(v.begin(), v.end());


	int i, j, k;
	for (int i2 = 0; i2 < m; i2++) {
		scanf("%d %d %d", &i, &j, &k);
		int count = 0;
		for (int i1 = 0; i1 < v.size(); i1++) {
			if (v[i1].second >= i && v[i1].second <= j) {
				count++;
			}
			if (count == k) {
				printf("%d\n", v[i1].first);
				break;
			}
		}
	}

}