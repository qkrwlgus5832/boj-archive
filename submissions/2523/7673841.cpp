#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int N;

void Ehrqkfh() {

	for (int i = 0; i < N ; i++) {
	
		
		for (int j = 0; j <= i; j++) {

			printf("*");


		}

		printf("\n");
	}
}





void rjRnfh() {

	for (int i = 0; i < N -1 ; i++ ) {

	

		for (int j = 0; j < N-(i+1); j++) {

			printf("*");


		}

		printf("\n");
	}
}



int main() {
	cin >> N;

	Ehrqkfh();

	
	
	
	rjRnfh();


}