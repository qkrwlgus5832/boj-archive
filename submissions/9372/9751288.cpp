#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>


using namespace std;

int T;
int N;
int M;
int tmp1;
int tmp2;
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);

		for (int i = 0; i < M; i++) {
			scanf("%d %d", &tmp1, &tmp2);
		}
		printf("%d\n", N - 1);
	}



}