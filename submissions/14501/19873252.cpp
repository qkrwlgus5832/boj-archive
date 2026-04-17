#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <int, int>> v;

int dp[17];

int N;

void recursion(int i, int cost) {
	for (int j = i; j <= N + 1; j++) {
		dp[j] = max(dp[j], cost);
	}
	if ((i >= N+1) || (i + v[i].first > N + 1)) {
		return;
	}
	recursion(i + v[i].first, cost + v[i].second);
}

int main() {

	cin >> N;
	v.resize(N + 1);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	for (int i = 1; i <= N; i++) {
		recursion(i, dp[i]);
	}
	int result = 0;
	for (int i = 1; i <= N + 1; i++) {
		result = max(result, dp[i]);

	}
	cout << result;
	//system("Pause");
}