#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int d;
int e;


int a[100000];

int b[10000];
int c[10000];

int main() {
	scanf("%d %d", &d, &e);

	for (int r = 0; r < d; r++) {
		scanf("%d ", &a[r]);
	}

	for (int q = 0; q < e; q++) {
		scanf("%d %d", &b[q], &c[q]);
	}

	for (int j = 0; j < d; j++) {
		if (j == 0) {
			continue;
		}
		a[j] = a[j - 1] + a[j];
	}
	
	
	for (int i = 0; i < e; i++) {
		if (i == 0) {
			printf("%d\n", a[c[i]-1]);
			continue;
		}
		printf("%d\n", a[c[i]-1] - a[b[i]-2]);
	}
	
}
