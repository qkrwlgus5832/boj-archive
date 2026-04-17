#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;

int N1[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		N1[tmp]++;
	}
	unsigned long long sum = 0;

	//int i = 10000;
	for (int i = 0; i <= 10000; i++) {
	if (N1[i] > 0) {
		//unsigned long long tmp1 = (unsigned long long) N1[i] * (N1[i] - 1) / 2;
		//unsigned long long tmp2 = i * i;

		sum = sum + (unsigned long long) N1[i] * (N1[i] - 1) / 2 * i * i;
	}
		for (int j = i + 1; j <= 10000; j++) {
			sum += (unsigned long long) N1[i] * N1[j] * i * j;
		}
	}
	//}

	cout << sum;
	//system("Pause");
}