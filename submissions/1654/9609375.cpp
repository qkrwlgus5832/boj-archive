#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
int K;
int N;

long long lansune(long long x) {
	long long result = 0;
	for (int i = 0; i < K; i++) {
		result = result + v[i] / x;
	}

	return result;

}


long long binary_search_(long long x, long long y, long long x1) {
	if (x + 1 == y) {
		if (lansune(y) >= x1)
			return y;
		else
			return x;
	}
	else if (x == y)
		return x;

	else if (lansune((x + y) / 2) >= x1)
		return binary_search_((x + y) / 2, y, x1);

	else if (lansune((x + y) / 2) < x1)
		return binary_search_(x, (x + y) / 2 - 1, x1);


}
int main() {
	cin >> K >> N;
	int tmp;
	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	cout << binary_search_(1, v[v.size()-1], N);



}