#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int L, P, V;
int main() {
	while (1) {
		scanf("%d %d %d", &L, &P, &V);
		if (L == 0 && P == 0 && V == 0)
			return 0;
		else {
			int t = V / P;
			int t2 = V % P;
			int t1 = t * L;

			if (t2 >= L) {
				printf("Case 1: %d\n", t1 + L);
			}
			else {
				printf("Case 2: %d\n", t1 + t2);
			}


		}

	}
}