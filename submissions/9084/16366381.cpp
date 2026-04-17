#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int T;

int DP(vector <int>& coins, int money) {
	int DP[21][10001] = { 0, };

	DP[0][0] = 1;
	coins.insert(coins.begin(), -1);

	for (int i = 1; i < coins.size(); i++) {
		for (int j = 0; j <= money; j++) {
	
			int count = 1;

			DP[i][j] += DP[i - 1][j];

			while (1) {
				if (j + coins[i] * count > money)
					break;
				
				DP[i][j + coins[i] * count] += DP[i - 1][j];

				count++;
			}
			if (i == 0)
				break;
		}
	}

	return DP[coins.size()-1][money];
}


int main() {
	cin >> T;
	int N;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int tmp;
		vector <int> coins;
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);
			coins.push_back(tmp);
		}
		int money;
		cin >> money;
		printf("%d\n", DP(coins, money));
	}
	//system("Pause");
}