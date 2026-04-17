#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


int main() {
	int S;
	int T;
	int D;

	cin >> S >> T >> D;

	cout << (D / (S * 2)) * T;
}