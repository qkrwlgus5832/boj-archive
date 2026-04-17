#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a;
int b;
int c;
int d;
int main() {
	scanf("%d %d %d", &a,&b,&c);
	if (1 <= a && 1 <= b && 1 <= c && a <= 100 && b <= 100 && c <= 100)
	{
		if (a <= b && b <= c)
			printf("%d",b);
		else if (c <= b && b <= a)
			printf("%d",b);
		else if (c <= a && a <= b)
			printf("%d",a);
		else if (b <= a && a <= c)
			printf("%d",a);
		else if (a <= c&&c <= b)
			printf("%d",c);
		else if (b <= c && c <= a)
			printf("%d",c);
	}
	
}