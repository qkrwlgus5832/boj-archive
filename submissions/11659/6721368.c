#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int N=0;
	int M=0;


	int a[100000];

	int b[100000];
	int c[10000];
	int r;
	int q;
	int j;
	int i;

	scanf("%d %d", &N, &M);

	for (r = 1; r <= N; r++) {
		scanf("%d ", &a[r]);
	}

	for (q = 1; q <= M; q++) {
		scanf("%d %d", &b[q], &c[q]);
	}

	for ( j = 1; j <= N; j++) {
		a[j+1] = a[j] + a[j+1];
	}
	
	
	for ( i = 1; i <= M; i++) {
		if (b[i] == 1 ) {
			printf("%d\n",a[c[i]]);
		}
		else {
		printf("%d\n", a[c[i]] - a[b[i]-1]);
		}
	}
	
}