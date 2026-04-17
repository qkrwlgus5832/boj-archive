#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N;
int M;


int a[100000];

int b[100000];
int c[10000];

int main() {
	scanf("%d %d", &N, &M);

	for (int r = 1; r <= N; r++) {
		scanf("%d ", &a[r]);
	}

	for (int q = 1; q <= M; q++) {
		scanf("%d %d", &b[q], &c[q]);
	}

	for (int j = 2; j <= N; j++) {
		a[j] = a[j - 1] + a[j];
	}
	
	
	for (int i = 1; i <= M; i++) {
		if (b[i] == 1 ) {
			printf("%d\n",a[c[i]]);
			continue;
		}
		printf("%d\n", a[c[i]] - a[b[i]-1]);
	}
	
}
