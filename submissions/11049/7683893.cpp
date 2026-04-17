#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;
int N1[10000][2];

unsigned long result =0;

void multiply() {
	for (int i = 0; i < N-1; i++) {
		result = result + N1[i][0] * N1[i][1] * N1[i + 1][1];

		N1[i+1][0] = N1[i][0];
	}
}





int main() {
	cin >> N;
	int r;
	int c;

	for (int i = 0; i < N; i++) {
		cin >> r >> c;
		N1[i][0] = r;
		N1[i][1] = c;

	}

	multiply();

	cout << result;



}