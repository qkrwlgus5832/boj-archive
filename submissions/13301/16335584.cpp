#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

long long DP[82];

int main() {
	int N;
	cin >> N;
	DP[1] = 1;
	DP[2] = 1;

	for (int i = 3; i <= N + 1; i++) {
		DP[i] = DP[i - 2] + DP[i - 1];
	}
	cout << DP[N] * 2 + DP[N + 1] * 2;
	//system("Pause");

}