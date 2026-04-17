#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int N;

void star() {
	for (int i = N-1; i >=1; i--) {

		for (int j = 0; j < i; j++) {
			printf(" ");
		}
		if (i == N - 1) {
			printf("*");
		}
		else {
			printf("*");
			for (int i1 = 0; i1 < (N - i - 2) * 2 + 1; i1++)
				printf(" ");
			printf("*");
		}
		printf("\n");
	}
	for (int i = 0; i < N * 2 - 1; i++) {
		printf("*");
	}

}




int main() {

	cin >> N;




	star();

}