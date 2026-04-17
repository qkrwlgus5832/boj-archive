#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int N;
int B, C;
int A[1000001];

int main() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		A[i] = tmp;
	}

	cin >> B >> C;

	long long result = 0;
	for (int i = 0; i < N; i++) {
		int count = 1;
		A[i] = A[i] - B;

		if (A[i] >= 1) {
			if (A[i] % C == 0) {
				count = count + A[i] / C;
			}
			else {
				count = count + (A[i] / C) + 1;
			}
		}
		result = result + count;
	}
	cout << result;

}