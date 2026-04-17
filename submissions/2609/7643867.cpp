#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int a;
int b;
int min() {
	int a_1 = a;
	int b_1 = b;
	while (a_1 != b_1) {
		if (a_1 < b_1)
			a_1 = a_1 + a;
		else if (a_1 > b_1)
			b_1 = b_1 + b;
	}

	return a_1;
}

int max() {
	int c = min(a, b);

	for (int i = c; i >= 1; i--) {
		if (a%i == 0 && b%i == 0)
			return i;
	}



}


int main() {


	cin >> a >> b;

	cout << max() << endl << min();

}