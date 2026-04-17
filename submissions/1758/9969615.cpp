#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector <int> v;
int tmp;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	long long result = 0;
	int j = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] - j <= 0)
			continue;
		else {
			result += v[i] - j;
			j++;

		}

	}

	cout << result;
}