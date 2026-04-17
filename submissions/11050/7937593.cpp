#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector <int> v;
int A[2000];

int n;


int factorial(int N) {
	if (N == 0)
		return 1;

	else
		return factorial(N - 1) * N;
}
int main() {
	int N;
	int K;
	cin >> N >> K;


	cout << factorial(N)/(factorial(K) * factorial(N-K)) ;

}
