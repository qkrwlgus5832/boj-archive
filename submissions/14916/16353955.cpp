#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int DP[100001];

void setDPvalue(int index, int value, int inputmax) {
	if (index <= inputmax) {
		if (DP[index] == 0)
			DP[index] = value;
		else
			DP[index] = min(DP[index], value);
	}
}
int main() {

	int n;
	cin >> n;
	DP[2] = 1;
	DP[5] = 1;
	for (int i = 1; i <= n; i++) {
		if (DP[i] >= 1) {
			setDPvalue(i + 2, DP[i] + 1, n);
			setDPvalue(i + 5, DP[i] + 1, n);
		}
	}
	if (DP[n] == 0)
		cout << -1;
	else
		cout << DP[n];
	//system("Pause");
}