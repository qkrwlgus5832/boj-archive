#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int N;
int main() {
	cin >> N;

	for (int i = N; i >= 1; i--) {

		for (int i1 = 1; i1 <= N-i; i1++) {
			printf(" ");
		}
		for (int j = 0; j <2*i-1 ; j++) {
			
			printf("*");
		}
		printf("\n");
	}


}