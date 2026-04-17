#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;


int dp[1001][3][31];
vector <int> input;

int T, W;

void init() {
	for (int j = W; j >= 0; j-=2) {
			dp[1][input[1]][j] = 1;
	}
	
}

int getReverse(int i) {
	if (i == 1)
		return 2;
	return 1;
}
int main() {
	cin >> T >> W;

	input.resize(T + 1);


	input[0] = -1;
	for (int i = 1; i <= T; i++) {
		scanf("%d", &input[i]);
	
	}
	
	init();
	

	for (int i = 2; i < input.size(); i++) {
		for (int w = 0; w <= W; w++) {
			if (w == W) {
				dp[i][input[i]][w] = dp[i - 1][input[i]][w] + 1;
				dp[i][getReverse(input[i])][w] = dp[i - 1][getReverse(input[i])][w];
			}
			else {
				dp[i][input[i]][w] = max(dp[i - 1][input[i]][w] + 1, dp[i - 1][getReverse(input[i])][w + 1] + 1);
				dp[i][getReverse(input[i])][w] = max(dp[i - 1][getReverse(input[i])][w], dp[i - 1][input[i]][w + 1]);
			}
		}

	}
	int result = 0;
	for (int w = 0; w <= W; w++) {
		result = max(result, dp[input.size() - 1][1][w]);
		result = max(result, dp[input.size() - 1][2][w]);
	}
	cout << result;
	//system("Pause");
}