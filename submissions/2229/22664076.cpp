#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


vector <int> v;
int dp[1001];

int main() {
	int N;
	cin >> N;

	v.resize(N + 1);

	int input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		v[i] = input;
	}

	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		int maxValue = -1;
		int minValue = INT_MAX;

		for (int j = i; j >= 1; j--) {
			maxValue = max(maxValue, v[j]);
			minValue = min(minValue, v[j]);

			dp[i] = max(dp[i], dp[j - 1] + maxValue - minValue);
		}
	}

	cout << dp[N];
	//system("Pause");
}
