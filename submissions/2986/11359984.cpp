#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

int N;
bool check[100000];

int j;
void erache() {
	for (int i = 2; i <= (int)sqrt(N); i++) {
		if (check[i] == false) {
			j = 2;
			while (1) {
				if (i*j > sqrt(N))
					break;
				else if (check[i*j] == false){
					check[i*j] = true;
					
				}
				j++;

			}
		}

	}

}
int main() {
	cin >> N;







		erache();
		int flag = 0;


		for (int i = 2; i <= (int)sqrt(N); i++) {
			if (check[i] == false) {
				if (N % i == 0) {
					cout << N - N / i;
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) {
			cout << N - 1;
		}

}

