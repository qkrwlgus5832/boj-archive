#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int N;

void Ehrqkfh() {

	for (int i = N; i >= 2 ; i--) {

		for (int i1 = 1; i1 <= N-i; i1++) 
			printf(" ");

		
		for (int j = 0; j <2*i-1; j++) {

			printf("*");


		}

		printf("\n");
	}
}





void rjRnfh() {

	for (int i = 2; i <= N; i ++ ) {

		for (int i1 = 1; i1 <= N - i; i1++)
			printf(" ");


		for (int j = 0; j <2 * i - 1; j++) {

			printf("*");


		}

		printf("\n");
	}
}



int main() {
	cin >> N;

	Ehrqkfh();

	for (int i = 0; i < N - 1; i++)
		printf(" ");
	printf("*");

	
	printf("\n");
	rjRnfh();


}