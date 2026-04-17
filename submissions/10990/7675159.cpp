#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
int N;


void star(int n) {
		
		for (int i = 1; i <= n; i++) {
			
			for (int j = 0; j < (n - i); j++)
				printf(" ");
			if (i == 1) {
				printf("*\n");
				continue;
			}
			printf("*");
		
			 if (i == 2) {
				printf(" ");
			}
			else {
				for (int j = 0; j < (i - 2) * 2 + 1; j++ ) {
					printf(" ");
				}
			}
			printf("*");

			printf("\n");
		}
	}




int main() {
	cin >> N;


	star(N);

}