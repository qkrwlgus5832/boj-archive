#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int N;

int N1[2000000];

void recursion(int n) {
	if (n == 3) {
		N1[2] = 1;
		return;
	}
	else if (n == 6) {
		recursion(n - 1);
		N1[5] = 2;
	}
	else {
		recursion(n - 1);
		if (n % 6 == 0)
			N1[n - 1] = N1[(n / 6) - 1] + 2;
		else if (n % 3 == 0)
			N1[n - 1] = N1[(n / 3) - 1] + 1;
		else if (n % 3 == 1)
			N1[n - 1] = N1[n - 2] + 1;
		else if (n % 3 == 2)
			N1[n - 1] = N1[n - 2] + 1;
	}


}


void min(int n) {
	for (int i = 3; i <= n; i++) {
		if (i == 3) {
			N1[i - 1] = 1;
		}
		else if (i == 6) {
			N1[i - 1] = 2;
		}
		else {

			if (i % 6 == 0)
				N1[i - 1] = N1[(i / 6) - 1] + 2;
			else if (i % 3 == 0)
				N1[i - 1] = N1[(i / 3) - 1] + 1;
			else if (i % 3 == 1)
				N1[i - 1] = N1[i - 2] + 1;
			else if (i % 3 == 2)
				N1[i - 1] = N1[i - 2] + 1;
		}

	}

}
int main() {
	cin >> N;
	N1[0] = 1;
	N1[1] = 1;


	min(N);
	cout << N1[N - 1];

}