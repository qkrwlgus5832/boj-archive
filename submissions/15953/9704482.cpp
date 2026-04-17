#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;


int T;

int tkd1[200];
int tkd2[100];


int main() {
	cin >> T;
	int a, b;

	int j = 1;
	int sum = 500;
	int count = 0;


	for (int i = 0; i < 6; i++) {
		for (int j1 = count+1;  j1 <= count+1+j; j1++) {
			tkd1[j1] = sum;
		}
		count = count + j;
		j++;
		if (j == 2)
			sum = sum - 200;
		else if (j == 3)
			sum = sum - 100;
		else if (j == 4)
			sum = sum - 150;
		else if (j == 5)
			sum = sum - 20;
		else if (j == 6)
			sum = sum - 20;
	}





	sum = 512;
	j = 1;
	 count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j1 = count+1; j1 <= count+1+j; j1++) {
			tkd2[j1] = sum;
		}
		count = count + j;
		j = j * 2;
		
		if (j == 2)
			sum = sum / 2;
		else if (j == 4)
			sum = sum / 2;
		else if (j == 8)
			sum = sum / 2;
		else if (j == 16)
			sum = sum / 2;
	}




	int tmpa, tmpb;
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &a, &b);
		tmpa = tkd1[a];
		tmpb = tkd2[b];
		if (a >= 22)
			tmpa = 0;
		if (b >= 32)
			tmpb = 0;

		printf("%d\n", (tmpa+tmpb) * 10000);
	}


}