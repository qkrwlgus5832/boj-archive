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
	if (a.second == b.second) {
		return a.first > b.first;
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

	int tmp = 0;





	for (int i = 0; i < v.size(); i++) {
		
		if (tmp == v[i].second) {
			int f = 0;
			for (int i1 = 1; i1 < v[i].second; i1++) {
				if (dp[i1] == 0) {
					dp[i1] = v[i1].first;
					f = 1;
					break;
				}
			}
			if (f == 1)
				continue;
			
			int mind = dp[1];
			int mini = 1;
			for (int i1 = 1; i1 < v[i].second; i1++) {
				if (dp[i1] < mind) {
					mini = i1;
					mind = dp[i1];
				
				}
			}
			if (dp[mini] < v[i].first)
			dp[mini] = v[i].first;
		}
		else {
			dp[v[i].second] = v[i].first;
			tmp = v[i].second;
		}

		
	}

	int result = 0;
	for (int i = 1; i <= 10000; i++) {
		result += dp[i];
	}
	cout << result;

}
