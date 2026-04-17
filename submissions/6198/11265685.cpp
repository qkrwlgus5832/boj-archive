#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector <pair <int, int>> v;
set <int> s;
int main() {
	int N;
	int tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {

		scanf("%d", &tmp);
		v.push_back(make_pair(tmp, i + 1));
	}

	sort(v.begin(), v.end());

	long long result = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (i == v.size() - 1) {
			result = N - v[i].second;
			s.insert(v[i].second);

		}
		else {
			auto itr = s.upper_bound(v[i].second);
			if (itr != s.end()) {
				result += *itr - v[i].second - 1;
			}
			else {
				result += N - v[i].second;
			}
			s.insert(v[i].second);

		}
	}
	cout << result;

}