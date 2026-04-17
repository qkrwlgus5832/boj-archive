#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int n;
int M;
int fibonacci(int N) {
	if (N == 0)
		return 0;
	else if (N == 1)
		return 1;
	else
		return fibonacci(N - 1) + fibonacci(N - 2);

}



int main() {

	cin >> n;
	cout << fibonacci(n);
}