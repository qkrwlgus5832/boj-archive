#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

string tmp;
long long DP[41];
int main() {

	cin >> tmp;
	DP[0] = 1;




	for (int i = 1; i < tmp.size(); i++) {

		DP[i] = DP[i - 1];

		if (i == 1) {
			if ((tmp.at(i - 1) -'0' ) * 10   + (tmp.at(i) - '0') <= 34)
				DP[i] = DP[i] + DP[i - 1];
		}
		else {
			if ((tmp.at(i - 1) - '0') * 10 + (tmp.at(i) - '0') <= 34)
				DP[i] = DP[i] + DP[i - 2];
		}


	}
	cout << DP[tmp.size() - 1];

}