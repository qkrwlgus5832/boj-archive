#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int fibonacchi(int n1) {
	if (n1 == 0)
		return 0;
	else if (n1 == 1)
		return 1;
	else
		return fibonacchi(n1 - 1) + fibonacchi(n1 - 2);
}




int main() {
	int n;
	cin >> n;


	cout << fibonacchi(n);


}