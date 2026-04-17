#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int n;
int DP[1001];
int main() {
	cin >> n;
	DP[1] = 1;
	DP[2] = 3;
	for (int i = 3; i <= n; i++)
		DP[i] = (DP[i - 1] + DP[i - 2] + DP[i - 2]) % 10007;


	cout << DP[n];

}