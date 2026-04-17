#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dp[101][100001];

int N, K;

struct info {
	int a; int b; int c; int d;
};

vector <info> v;

int main() {
	cin >> N >> K;

	int a, b, c, d;

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		v.push_back({ a,b,c,d });
	}


	dp[0][v[0].a] = v[0].b;
	dp[0][v[0].c] = v[0].d;

	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j + v[i].a] = max(dp[i][j + v[i].a], dp[i - 1][j] + v[i].b);
			dp[i][j + v[i].c] = max(dp[i][j + v[i].c] , dp[i - 1][j] + v[i].d);
		}
	}

	int result = 0;

	for (int i = 1; i <= K; i++) {
		result = max(result,dp[N - 1][i]);
	}
	cout << result;
	//system("Pause");
}
