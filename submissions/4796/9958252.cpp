#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int L, P, V;
int main() {
	int i = 1;
	while (1) {
		scanf("%d %d %d", &L, &P, &V);
		if (L == 0 && P == 0 && V == 0)
			return 0;
		else {
			int t = V / P;
			int t2 = V % P;
			int t1 = t * L;

			if (t2 >= L) {
				printf("Case %d: %d\n",i++, t1 + L);
			}
			else {
				printf("Case %d: %d\n",i++, t1 + t2);
			}


		}

	}
}