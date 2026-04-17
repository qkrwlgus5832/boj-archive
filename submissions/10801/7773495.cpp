#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


int A[11];
int B[11];

int main() {
	int a = 0;
	int b = 0;
	for (int i = 0; i < 10; i++)
		cin >> A[i];
	for (int i = 0; i < 10; i++)
		cin >> B[i];

	for (int i = 0; i < 10; i++) {
		if (A[i] > B[i])
			a = a + 1;
		else if (A[i] < B[i])
			b = b + 1;
	

	}

	if (a == b)
		cout << "D";
	else if (a > b)
		cout << "A";
	else if (a > b)
		cout << "B";


}