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

			for (int i1 = 0; i1 < i; i1++) {
				if (i1 == i - 1)
					printf("*");
				else
				printf("* ");

			}
			printf("\n");
			
		}
}




int main() {
	cin >> N;


	star(N);

}