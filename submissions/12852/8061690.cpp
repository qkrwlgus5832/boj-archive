#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;

int N1[2000000];
vector <int> v;

int N2[1000001];


void min(int n) {
	for (int i = 3; i <= n; i++) {
			if (i % 6 == 0) {
				N1[i - 1] = min(N1[(i / 2) - 1] + 1, N1[i - 2] + 1);
				N1[i - 1] = min(N1[i - 1], N1[(i / 3) - 1] + 1);
				if (N1[i - 1] == N1[(i / 3) - 1] + 1)
					N2[i - 1] = (i / 3);
				else if (N1[i - 1] = N1[(i / 2) - 1] + 1)
					N2[i - 1] = i / 2;
				else if (N1[i - 1] == N1[i - 2] + 1)
					N2[i - 1] = i - 1;
		
			}
			else if (i % 3 == 0) {
				N1[i - 1] = min(N1[i - 2] + 1, N1[(i / 3) - 1] + 1);
				if (N1[i - 1] == N1[i - 2] + 1)
					N2[i - 1] = i -1;
				else if (N1[i - 1] == N1[(i / 3) - 1] + 1)
					N2[i - 1] = i/3;

			}
			else if (i % 2 == 0) {
				N1[i - 1] = min(N1[i - 2] + 1, N1[(i / 2) - 1] + 1);
				if (N1[i - 1] == N1[(i /2) -1 ] + 1)
					N2[i - 1] = i /2;
				else if (N1[i - 1] == N1[i - 2] + 1)
					N2[i - 1] = i -1;
			}
			else {
				N1[i - 1] = N1[i - 2] + 1;
				N2[i - 1] = i - 1;
			}
		}

	

}
int main() {
	cin >> N;
	N1[0] = 0;
	N1[1] = 1;
	N1[2] = 1;




	N2[0] = 0;
	N2[1] = 1;
	N2[2] = 1;




	if (N == 1)
		cout << "1";
	else if (N == 2) {
		cout << "2" << " " << "1";
	}
	else if (N == 3) {
		cout << "3" << " " << "1";
	}
	else {
		
		min(N);
		cout << N << " ";

		int N3 = N;
		while (N3 != 1) {
			int a = N2[N3 - 1];
			if (a==1)
				cout << N2[N3 - 1];
			else
				cout << N2[N3 - 1] << " ";
			N3 = a;
		}
	}





}



