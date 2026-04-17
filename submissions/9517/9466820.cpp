#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;



int K, N, T;
char Z;
int result;
int hap = 0;
int main() {
	cin >> K;
	cin >> N;



	for (int i = 0; i < N; i++) {
		cin >> T >> Z;
		hap = hap + T;
		if (hap > 210) {
			break;
		}
		if (Z=='T')
		K = (K + 1) % 9;
	}

	cout << K;

}