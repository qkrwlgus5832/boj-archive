#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int A[2000];
int DP[2000];
int n;
int main() {

	fill_n(DP, 1001, 1);
	int N;
	cin >> N;
	int count = 1;


	for (int i = 0; i < N; i++)
		cin >> A[i];
	int max = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] < A[j + 1]) {
				DP[i] = DP[i] + 1;
			}
		}
		if (DP[i] >= max)
			max = DP[i];
	}
		
	cout << max;

	
}