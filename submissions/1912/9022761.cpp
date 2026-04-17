#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;


int N1[100001];
int DP[100001];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> N1[i];



	DP[0] = N1[0];
	int max1 = DP[0];

	for (int i = 1; i < n; i++) {
		DP[i] = max(N1[i], DP[i - 1] + N1[i]);
		if (max1 <= DP[i]) {
			max1 = DP[i];
		}
	}

	cout << max1;



}