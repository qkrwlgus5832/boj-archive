#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int T[16];
int P[16];
int N;
int DP[16];


void DP2() {
	int last = 0; 
	for (int i2 = N - 1; i2 >= 0; i2 = i2 - 1) { 
		if (T[i2] + i2 > N) 
			DP[i2] = 0;
		else {
			int f = 1;
			for (int j = 0; j < T[i2]; j++) {   
				if (DP[i2 + j] != 0) 
					f = 0;  
			}
			if (f == 0) {
				if (P[i2] + DP[i2+T[i2]] > DP[last]) {
					if (DP[i2 + T[i2]] != 0) {
						DP[i2] = P[i2] + DP[i2 + T[i2]];
					}
					else if(i2+T[i2] == N) {
						DP[i2] = P[i2];
					}
					else
					{
						for (int q = 1; q < T[last]; q++) {
							if (DP[last + q] != 0 && last + q >i2 + T[i2] - 1) {
								DP[i2] = P[i2] + DP[last + q];
								break;
							}
						}
					}
					last = i2;	
					/*for (int q = 1; q < T[last]; q++) {
						if (DP[last+q] != 0 && last+q >i2+T[i2]-1 ) {
							DP[i2] = DP[i2] + DP[last+q];
							break;
						}
					}
					*/
				}
				
			}

			else {
				DP[i2] = P[i2] + DP[last];   
				last = i2; 
			}
		}	
	}
	if (DP[0] == 0)
		DP[0] = DP[last];
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	DP2();  

	cout << DP[0]; 
}
