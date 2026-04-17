#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N;
int M;


int a[100000] = { 0 };

int b[100000] = { 0 };
int c[10000] = { 0 };

int main() {
	scanf("%d %d", &N, &M);

	for (int r = 1; r <= N; r++) {
		scanf("%d ", &a[r]);
	}

	for (int q = 1; q <= M; q++) {
		scanf("%d %d", &b[q], &c[q]);
	}

	for (int j = 1; j <= N; j++) {
		a[j+1] = a[j] + a[j+1];
	}
	
	
	for (int i = 1; i <= M; i++) {
		if (b[i] == 1 ) {
			printf("%d\n",a[c[i]]);
		}
		else {
		printf("%d\n", a[c[i]] - a[b[i]-1]);
		}
	}
	
}
