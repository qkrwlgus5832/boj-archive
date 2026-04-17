#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int DP[2001];
bool check[2001][2001];

int gcd(int a, int b) {
	if (a%b == 0) return b;
	return gcd(b, a%b);
}


bool getMaxDivisor(int x, int y) {
	int standard = min(x, y);
	int maxdivisour = gcd(x, y);
	if (check[x / maxdivisour][y / maxdivisour] == false) {
		check[x / maxdivisour][y / maxdivisour] = true;
		return true;
	}
	else
		return false;
}

int main() {
	int D1, D2;
	cin >> D1 >> D2;

	for (int i = D1; i <= D2; i++) {
		DP[i] += DP[i - 1] + (i-1);
		for (int j = 1; j < i; j++) {
			if (getMaxDivisor(i, j) == false)
				DP[i]--;
		}
	}
	cout << DP[D2] + 1;
	//system("Pause");
}