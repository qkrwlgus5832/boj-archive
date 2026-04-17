#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int DP[31];
int main() {
	cin >> N;	

	if (N % 2 == 1) {
		cout << 0;
	}
	else {
		DP[1] = 3;
		DP[2] = 11;
		for (int i = 3; i <= N / 2; i++) {
			DP[i] = DP[i - 1] + 3 * DP[i - 1] - DP[i - 2];
		}
		cout << DP[N/2];
	}


}