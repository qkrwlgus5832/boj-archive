#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector <int> coins;
int DP[10001];

int main() {
	cin >> n >> k;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		coins.push_back(tmp);
	}
	sort(coins.begin(), coins.end());
	for (int i = 0; i < n; i++) {

		for (int j = coins[i]; j <= k; j++) {
			if (j == coins[i])
				DP[j] = 1;
			if (DP[j - coins[i]] == 0) {
				continue;
			}
			else if (DP[j] == 0) {
				DP[j] = DP[j - coins[i]] + 1;
			}
			
			else if (DP[j - coins[i]] != 0)
				DP[j] = min(DP[j], 1 + DP[j - coins[i]]);
		}
	}
	if (DP[k] == 0)
		cout << -1;
	else
		cout << DP[k];
	//system("Pause");
}