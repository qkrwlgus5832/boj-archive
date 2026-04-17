#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> v;

int N, M;

long long budget(int x) {
	long long result = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= x)
			result = result + x;
		else
			result = result + v[i];
	}

	return result;

}



long long binary_search_(int x, int y, long long x1) {
	if (x + 1 == y) {
		if (budget(y) <= x1)
			return y;
		else
			return x;
	}
	else if (x == y)
		return x;
	else if (budget((x + y) / 2) > x1)
		return binary_search_(x, (x + y) / 2 - 1, x1);
	else if (budget((x+y)/2) <=x1)
		return binary_search_((x+y)/2, y, x1);
}


int main() {
	
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	long long M;
	cin >> M;
	sort(v.begin(), v.end());
	cout << binary_search_(1, v[v.size() - 1], M);


}