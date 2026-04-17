#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int A;
int B;
int V;






int main() {
	scanf("%d %d %d", &A, &B, &V);


	int result;
	if (((V - A) % (A - B)) == 0) {

		 result = (V - A) / (A - B) + 1;
	}
	else {
		result = (V - A) / (A - B) + 2;

	}
	printf("%d", result);


}
