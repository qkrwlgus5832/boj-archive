#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int dp[10000001];
int birth[10000001];
int a, b, d, N;


void recursion() {	
	for (int j = 0; j <= N; j++) {
		for (int i = a; i < b; i++) {
			if (j + i > N)
				break;
			birth[j + i] += (birth[j]) % 1000;
		}
	}
}


int main() {
	cin >> a >> b >> d >> N;

	birth[0] = 1;

	recursion();

	int result = 0;
	for (int i = N; i > N - d; i--) {
		result = (result + birth[i]) % 1000;
	}
	cout << result;
}