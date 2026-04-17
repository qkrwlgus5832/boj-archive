#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[101][101][101];

int result = 0;
int main() {
	string input1, input2, input3;

	cin >> input1 >> input2 >> input3;

	for (int i = 0; i < input1.size(); i++) {
		for (int j = 0; j < input2.size(); j++) {
			for (int r = 0; r < input3.size(); r++) {
				if (i == 0 && j == 0 && r == 0) {
					if (input1[i] == input2[j] && input2[j] == input3[r])
						dp[i][j][r] = 1;
				}
				else {
					if (input1[i] == input2[j] && input2[j] == input3[r]) {
						if (i - 1 < 0 || j - 1 < 0 || r - 1 < 0) {
							dp[i][j][r] = 1;
						
						}
						else
							dp[i][j][r] = dp[i - 1][j - 1][r - 1] + 1;
					}
					else {
						if (i - 1 < 0 && j - 1 < 0) {
							dp[i][j][r] = dp[i][j][r - 1];
						}
						else if (j - 1 < 0 && r - 1 < 0) {
							dp[i][j][r] = dp[i-1][j][r];
						}
						else if (i - 1 < 0 && r - 1 < 0) {
							dp[i][j][r] = dp[i][j-1][r];
						}
						else if (i - 1 < 0) {
							dp[i][j][r] = max(dp[i][j-1][r], dp[i][j][r - 1]);
						}
						else if (j - 1 < 0) {
							dp[i][j][r] = max(dp[i- 1][j][r], dp[i][j][r - 1]);
						}
						else if (r - 1 < 0 ){
							dp[i][j][r] = max(dp[i -1][j][r], dp[i][j - 1][r]);
						}
						else {
							dp[i][j][r] = max(dp[i - 1][j][r], dp[i][j - 1][r]);
							dp[i][j][r] = max(dp[i][j][r], dp[i][j][r-1]);
						}
					}
				}
				//cout << dp[i][j][r];
				result = max(result, dp[i][j][r]);
			}
		}
	}
	cout << result;
	//system("Pause");
}