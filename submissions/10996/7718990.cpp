#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int N;

string N1[101][300];

void star(int n) {
	if (n == 1) {
		N1[0][0] = "*";
		return;
	}
	else if (n == 2) {
		N1[1][0] = "*";
		N1[1][1] = " *";
		N1[1][2] = "*";
		N1[1][3] = " *";
	}
	else if (n%2==0){
		star(n - 1);
		for (int i = 0; i < (n - 1) * 2; i++) {
			if (i % 2 == 0)
				N1[n - 1][i] = N1[n - 2][i];
			else
				N1[n - 1][i] = N1[n - 2][i] + " *";

			N1[n - 1][n * 2 - 2] = N1[n - 1][0];
			N1[n - 1][n * 2 - 1] = N1[n - 1][1];
		}



	}
	else if (n % 2 == 1) {
		star(n - 1);
		for (int i = 0; i < (n - 1) * 2; i++) {
			if (i % 2 == 1)
				N1[n - 1][i] = N1[n - 2][i];
			else
				N1[n - 1][i] = N1[n - 2][i] + " *";

			N1[n - 1][n * 2 - 2] = N1[n - 1][0];
			N1[n - 1][n * 2 - 1] = N1[n - 1][1];
		}
	}
}

int main() {
	cin >> N;
	star(N);
	for (int i = 0; i < N * 2; i++) {
		cout << N1[N - 1][i] << endl;
	}
}