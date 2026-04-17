#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long N;
int main() {
	scanf("%d", &N);

	if (2 <= N && N<= 7)
		printf("2");
	else if (8 <= N && N<= 19)
		printf("3");
	else if (20 <= N && N<= 37)
		printf("4");
	else if (38 <= N && N<= 61)
		printf("5");
	else if (62 <= N && N<= 70)
		printf("6");

	
		return 0;
}