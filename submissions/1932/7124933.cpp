#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int v[1000000];
int dp[1000000];

void dpdp() {
	int n1 = n;
	int count = 0;
	for (int i = n*(n + 1) / 2 -1 - n; i >=0; i--) {
		if (n1 == 5) {
			dp[i] = v[i] + max(v[i + (n1 - 1)], v[i + n1]);
			count = count + 1;

			if (count == n1 - 1) {
				n1 = n1 - 1;
				count = 0;

			}

		}
		else {
			dp[i] = v[i] + max(dp[i + (n1 - 1)], dp[i + n1]);
			count = count + 1;

			if (count == n1 - 1) {
				n1 = n1 - 1;
				count = 0;

			}
		}
	}
}

int main() {

	cin >> n;

	
	for (int i = 0; i < n*(n + 1) / 2; i++)
		cin >> v[i];


	dpdp();
	cout << dp[0];
}