#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;
vector <int> v;
int N;
int N1[80001];
int DP[80001];
stack <int> st;
int main() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		N1[i] = tmp;
	}



	int result = 0;
	int max1 = N1[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		if (N1[i] > max1) {
			DP[i] = N - 1 - i;
			max1 = N1[i];
		}
		else {
			if (N1[i] > N1[i + 1]) {
				DP[i] = DP[i + 1] + 1;
				if (i+2 < N && N1[i + 1] < N1[i + 2] && N1[i] > N1[i + 2])
					DP[i] =DP[i]+ DP[i + 2] + 1;
			}
			else {
				DP[i] = 0;
			}
		}
		result = result + DP[i];
	}

	cout << result;
}