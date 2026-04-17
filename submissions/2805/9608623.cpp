#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector <int> v;
//
long long tree(long long x) {
	long long result = 0;
	for (int i = 0; i < N; i++) {
		if (v[i] > x) {
			result = result + v[i] - x;
		}

	}
	return result;
}

long long binary_search_(long long x, long long y, long long x1) {
	if (x + 1 == y) {
		if (tree(y) >= x1)
			return y;
		return x;
	}
	else if (x==y)
		return x;
	else if (tree((x + y) / 2) >= x1)
		return binary_search_((x + y) / 2, y, x1);
	else if (tree(x + y) / 2 < x1)
		return binary_search_(x, (x + y) / 2 - 1, x1);

}




int main() {
	cin >> N >> M;

	int tmp;

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());




	cout << binary_search_(0, v[v.size() - 1]-1, M);




}