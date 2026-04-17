#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N;
int DP[1000001];
int main() {
	cin >> N;
	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= N; i++) {
		DP[i] = (DP[i - 1] + DP[i - 2]) % 15746;
	} 

	cout << DP[N];
}