#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int N;
string N1[101][1000];
string bla = "   ";
void star(int n) {

	if (n == 1) {
		N1[0][0] = "*";
		return;
	}
	else {

		star(n - 1);

		for (int i = 0; i < (1 + (n - 2) * 4); i++) {
			N1[n - 1][2 + i] = "* " + N1[n - 2][i] + " *";
		}



	
		N1[n - 1][0] = N1[n - 2][0] + "****";
		N1[n - 1][1] = "*" + bla + "*";

		N1[n - 1][4 * (n - 1) -1] = N1[n - 1][1];
		N1[n - 1][4 * (n - 1)] = N1[n - 1][0];
	
		
		bla = bla + "    ";






		}


	}

int main() {
	cin >> N;




	star(N);

	for (int i = 0; i < (N - 1) * 4+1; i++) {
		cout << N1[N - 1][i] << endl;
	}

}