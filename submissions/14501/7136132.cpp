#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T[100];
int P[100];
int N;
int count2 = 0;
vector <int> DP;


void dpdp() {

	for (int i = N - 1; i >= 0; i--) {
		if (T[i] + i > N)
			continue;
		else {
			int a = DP[i + T[i]];
			for (int j = 1; j < N - i - T[i]; j++) {
				if (a <= DP[i + T[i] + j])
					a = DP[i + T[i] + j];
			}
			DP[i] = P[i] + a;

		}

	}

}
int main() {

	cin >> N;
	for (int i = 0; i < 100; i++) {
		DP.push_back(0);
	}
	
	
	for (int i = 0; i < N; i++)
		cin >> T[i] >> P[i];
	dpdp();
	sort(DP.begin(), DP.begin()+N);
	cout << DP[N-1];
	
}
