#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;


vector < pair <int, int>> v;

int root;
int recursion(int x, int count, int x1) {
	if (v[x].first == 0 && v[x].second == 0) {
		if (x < x1)
			v[x].second = x1;
		else
			v[x].first = x1;
		return count;
	}
	else if (v[x].first == 0) {
		if (x1 < x) {
			v[x].first = x1;
			return count;
		}

		recursion(v[x].second, count + 1, x1);
	}
	else if (v[x].second == 0) {
		if (x1 > x) {
			v[x].second = x1;
			return count;
		}
		recursion(v[x].first, count + 1, x1);

	}
	else {
		if (x1 > x)
			recursion(v[x].second, count + 1, x1);
		else
			recursion(v[x].first, count + 1, x1);

	}
}


int main() {

	int N;
	cin >> N;

	v.resize(N+1);
	int tmp;
	long long result = 0;


	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
	/*	v[tmp].push_back(tmp);
		if (v.size() == 2 && v[N][0] > tmp) {
			swap(v[N][0], v[N][1]);
		}*/
		if (i == 0)
			root = tmp;
		else if (i>=1)
		result+= recursion(root , 1, tmp);
		printf("%d\n", result);

	}




}