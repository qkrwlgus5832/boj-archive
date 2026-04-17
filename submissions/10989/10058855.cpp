#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;


int dd[10001];



int main() {
	int N;
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		dd[tmp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < dd[i]; j++) {
			printf("%d\n", i);
		}
	}
}
