#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int factorial(int n1) {
	if (n1 == 0)
		return 1;
	else if (n1 == 1)
		return 1;
	else

		return factorial(n1 - 1) * n1;
}




int main() {
	int N;
	cin >> N;


	cout << factorial(N);


}