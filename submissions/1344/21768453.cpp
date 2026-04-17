#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;


double dp[19][19][19];
bool check[19];


void sosuCheck() {
	check[0] = true;
	check[1] = true;
	
	for (int i = 2; i <= 18; i++) {
		for (int j = 2; j < i; j++) {
			if (i % j == 0)
				check[i] = true;
		}
	}
}

void getAnswer() {

}
int main() {
	double A;
	double B;
	cin >> A >> B;

	A = A * 0.01;
	B = B * 0.01;

	dp[0][0][0] = 1;


	for (int t = 1; t <= 18; t++) {
		for (int i = 0; i <= 18; i++) { // A도 18번까지 득점할 수 있고
			for (int j = 0; j <= 18; j++) { // B도 18번까지 득점할수 있음
				if (i-1 >= 0)
					dp[t][i][j] += dp[t - 1][i - 1][j] * A * (1 - B);
				if (j-1 >= 0)
					dp[t][i][j] += dp[t - 1][i][j - 1] * B * (1 - A);
				if (i-1 >= 0 && j- 1>= 0)
					dp[t][i][j] += dp[t - 1][i - 1][j - 1] * A * B;

				dp[t][i][j] += dp[t - 1][i][j] * (1 - A) * (1 - B);

			}
		}
	}
	sosuCheck();

	double result = 0;

	for (int i = 0; i <= 18; i++) {
		for (int j = 0; j <= 18; j++) {
			if (check[i]== false || check[j] == false) {
				result += dp[18][i][j];
			}
		}
	}

	cout.precision(16);
	cout << result;
	//system("Pause");
}

