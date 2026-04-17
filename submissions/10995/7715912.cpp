#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int N;
string N1[101];

void star(int n) {
	string tmp = "*";
	for (int i = 0; i < n-1; i++) {
		tmp = tmp + " *";
	}

	for (int i = 0; i < n; i++) {
		if (i%2 == 0)
		N1[i] = tmp;
		else
		N1[i] = " " +tmp;
	}



}

int main() {
	cin >> N;




	star(N);

	for (int i = 0; i < N; i++){
		cout << N1[i] << endl;
	}

}