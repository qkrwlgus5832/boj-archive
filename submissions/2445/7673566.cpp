#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int N;

void Ehrqkfh() {

	for (int i = 1; i <= N-1 ; i++) {

		for (int i1 = 1; i1 <= i; i1++) 
			printf("*");

		
		for (int j = 0; j <2*N - i*2; j++) {

			printf(" ");


		}

		for (int i1 = 1; i1 <= i; i1++)
			printf("*");


		printf("\n");
	}
}





void rjRnfh() {

	for (int i = 1; i <= N - 1; i++) {

		for (int i1 = 1; i1 <= N-i; i1++)
			printf("*");


		for (int j = 0; j <2 * N - (N-i) * 2; j++) {

			printf(" ");


		}

		for (int i1 = 1; i1 <= N-i; i1++)
			printf("*");


		printf("\n");
	}
}



int main() {
	cin >> N;

	Ehrqkfh();


	for (int i = 0; i < 2 * N; i++) {
		printf("*");

	}
	printf("\n");
	rjRnfh();


}