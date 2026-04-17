#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string input1, input2;

int DP[1001][1001];
string dp[1001][1001];

string resultstring;

int main() {
	cin >> input1;
	cin >> input2;

	int result = 0;

	if (input1.size() < input2.size())
		swap(input1, input2);

	for (int i = 0; i < input1.size(); i++) {
		for (int j = 0; j < input2.size(); j++) {
			if (i == 0 && j == 0)
				DP[i][j] = input1[i] == input2[j];
			else if (input1[i] == input2[j]) {
				if (i - 1 < 0 || j - 1 < 0) {
					DP[i][j] = 1; dp[i][j] = input1[i];
				}
				else {
					DP[i][j] = DP[i - 1][j - 1] + 1; dp[i][j] = dp[i-1][j-1] + input1[i];
				}
			}
			else if (i - 1 < 0) {
				DP[i][j] = DP[i][j - 1];
				dp[i][j] = dp[i][j - 1];
			}
			else if (j - 1 < 0) {
				DP[i][j] = DP[i - 1][j];
				dp[i][j] = dp[i - 1][j];
			}
			else {
				if (DP[i - 1][j] > DP[i][j - 1]) {
					DP[i][j] = DP[i - 1][j];
					dp[i][j] = dp[i - 1][j];
				}
				else {
					DP[i][j] = DP[i][j - 1];
					dp[i][j] = dp[i][j - 1];
				}

				
			}
			if (DP[i][j] > result) {
				result = DP[i][j];
				resultstring = dp[i][j];
			}
			//result = max(result, DP[i][j]);
		}
	}

	cout << result << endl;
	cout << resultstring;
	//system("Pause");
}