#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int n;
int M;
int N1[100];
void fibonacci(int N) {
	if (N == 0)
		return;
	else if (N == 1)
		return;
	else {
		for (int i = 2; i <= N; i++) {
			N1[i] = N1[i - 2] + N1[i - 1];
	}
		

	}

}



int main() {
	N1[0] = 0;
	N1[1] = 1;

	cin >> n;
	fibonacci(n);
	cout << N1[n];
}