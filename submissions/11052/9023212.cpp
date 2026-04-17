#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int P[1001];
int DP[100001];
int N;
vector <int> v;
int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	v.push_back(0);
	int max = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (max <= v[j] + P[i - j])
				max = v[j] + P[i - j];
		}
		if (max <= P[i])
			max = P[i];
		v.push_back(max);
		max = 0;
	}
	sort(v.begin(), v.end());


	cout << v[v.size() - 1];
}