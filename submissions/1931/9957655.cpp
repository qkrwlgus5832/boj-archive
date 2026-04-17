#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector <pair <int, int>> v;
bool check[100001];
int N;
int tmp1, tmp2;


bool compare(pair <int, int> a, pair <int, int> b) {
	return a.second < b.second;
}



int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &tmp1, &tmp2);
		v.push_back(make_pair(tmp1, tmp2));

	}
	sort(v.begin(), v.end(), compare);






	int tmp = 0;
	int count = 0;
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first >= tmp) {
			tmp = v[i].second;
			count++;
			continue;

		}


	}
	cout << count;
}
