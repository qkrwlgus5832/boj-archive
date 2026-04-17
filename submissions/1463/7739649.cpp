#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;

int N1[2000000];



void min(int n) {
	for (int i = 3; i <= n; i++) {
		if (i == 3) {
			N1[i - 1] = 1;
		}
		
		else {

			if (i % 6 == 0)
				N1[i - 1] = N1[(i / 6) - 1] + 2;
			if (i % 3 == 0)
				if (i % 2 == 0)
					N1[i - 1] = min(N1[(i /2 ) -1] + 1, N1[(i/ 3) -1] + 1);
				else
				N1[i - 1] = N1[(i / 3) - 1] + 1;
			else if (i % 3 == 1) {
				if (i % 2 == 0)
					N1[i - 1] = min(N1[i - 2] + 1, N1[(i / 2) -1] + 1);
				else
				N1[i - 1] = N1[i - 2] + 1;
			}
			else if (i % 3 == 2) {
				if (i % 2 == 0)
					N1[i - 1] = min(N1[i - 2] + 1, N1[(i/2) -1] + 1);
				else
				N1[i - 1] = N1[i - 2] + 1;
			}
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