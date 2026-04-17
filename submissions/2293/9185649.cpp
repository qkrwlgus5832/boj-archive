#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

int n;
int k;

int arr[101];
int dp[10001];
int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

	}


	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j<= k; j++) {
			if (j == arr[i]) {
				dp[arr[i]]++;
				continue;
			}

			dp[j] = dp[j] + dp[j - arr[i] ];
		}
	}


	cout << dp[k];
}