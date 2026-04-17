#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int A;
int B;
int V;






int main() {
	scanf("%d %d %d", &A, &B, &V);
	int result = (V - A) /( A - B) + 1;

	printf("%d", result);


}
