#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N;
int K;
int f;
int N1[100];
int DP[100];
int last = 0;
void Max() {
	f = 0;
	for (int i = N-1 ; i>=0; i--) {
		if (K >= N1[i]) {
			f = i;
			break;
		}
	}


}

int Min() {
	int f1 = 0;
	
	while (K != 0) {
		Max();
		DP[f] = DP[last] + K / N1[f];
		last = f;
		K = K % N1[f];
		if (K == 0)
			f1 = DP[f];

	}
	return f1;
}





int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> N1[i];

	}
	int f2 = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (K >= N1[i]) {
			f2 = i;
			break;
		}
	}
	DP[f2] = K / N1[f2];
	last = f2;
	K = K % N1[f2];
	if (K == 0)
		cout << DP[f2];
	else	
	cout << Min();
}