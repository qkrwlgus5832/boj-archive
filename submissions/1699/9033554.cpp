#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int DP[100001];
int main() {

	cin >> N;

	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;
	int i1 = 2;
	for (int i = 4; i <= N; i++) {
		if (pow(i1, 2) == i) {
			DP[i] = 1;
			i1++;
		}
		else {
			int tmpi = i - pow(i1 - 1, 2);
			DP[i] = 1 + DP[tmpi];
			for (int i2 = 2; i2 < i1 - 1; i2++) {
				int tmpi = pow(i2, 2);
				DP[i] = min(DP[i], DP[tmpi] + DP[i - tmpi]);
			}
			
		}

	}


	cout << DP[N];
}