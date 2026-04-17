#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair <int, int>> v;

int n;
int d, p;

bool compare(pair <int, int> a, pair< int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}


int main() {
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p, &d);
		v.push_back(make_pair(p, d));
	}



	sort(v.begin(), v.end(), compare);


	int result = 0;
	int tmp = v[0].second;
	int ff = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second > tmp) {
			result += ff;
			ff = 0;
			tmp = v[i].second;
		}
		if (v[i].second >= tmp) {
			ff = max(ff, v[i].first);
		
		}
	}
	result += ff;
	cout << result;

}
