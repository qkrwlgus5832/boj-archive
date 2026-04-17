#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N;
int M;


int a[100000];

int b[100000];
int c[10000];

int main() {
	scanf("%d %d", &N, &M);

	for (int r = 0; r < N; r++) {
		scanf("%d ", &a[r]);
	}

	for (int q = 0; q < M; q++) {
		scanf("%d %d", &b[q], &c[q]);
	}

	for (int j = 0; j < N; j++) {
		if (j == 0) {
			continue;
		}
		a[j] = a[j - 1] + a[j];
	}
	
	
	for (int i = 0; i < M; i++) {
		if (b[i] == 1 ) {
			printf("%d\n",a[c[i]-1]);
			continue;
		}
		printf("%d\n", a[c[i]-1] - a[b[i]-2]);
	}
	
}
