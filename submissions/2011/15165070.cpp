#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>

using namespace std;

string input;

int DP[5001][2];



int main() {
	cin >> input;
	DP[0][0] = 1;
	DP[0][1] = 0;
	for (int i = 1; i < input.size(); i++) {
		DP[i][0] = (DP[i - 1][0] + DP[i - 1][1]) % 1000000;
		if ((input[i - 1] - '0') * 10 + (input[i] - '0') <= 26) {
			if (i - 2 < 0) {
				DP[i][1] = 1;
			}
			else
				DP[i][1] = (DP[i - 2][0] + DP[i - 2][1]) % 1000000;
		}
	}

	cout << (DP[input.size() - 1][0] + DP[input.size() - 1][1]) % 1000000;
	//system("Pause");
}