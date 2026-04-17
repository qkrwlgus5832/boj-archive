#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;
int DP[100];
int main() {

	cin >> N;

	DP[1] = 1;
	DP[2] = 1;

	for (int i = 3; i <= N; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	cout << DP[N];
}