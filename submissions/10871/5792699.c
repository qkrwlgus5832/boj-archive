#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int X;
int a;
int main() {
	scanf("%d %d", &N, &X);
	int *c = malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
		scanf(" %d", &c[i]);
	for (int i = 0; i < N; i++) {
		if (c[i] < X)
			printf("%d ", c[i]);
	}
}