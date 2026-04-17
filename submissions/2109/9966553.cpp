#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector <pair <int, int>> v;

int n;
int d, p;
int dp[10001];
bool check[10001];
bool compare(pair <int, int> a, pair< int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
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


	for (int i = 0; i < v.size(); i++) {
		for (int i1 = v[i].second; i1 >= 1; i1--) {
			if (dp[i1] == 0) {
				dp[i1] = v[i].first;
				break;
			}
		}
	}
	int result = 0;
	for (int i = 1; i <= 1000; i++) {
		result += dp[i];
	}

	cout << result;





}
