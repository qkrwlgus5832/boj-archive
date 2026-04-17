#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>
using namespace std;
int n, m;


int unionfind[1000001];
int s,tmp1, tmp2;
int find(int n) {
	if (unionfind[n] < 0)
		return n;
	unionfind[n] = find(unionfind[n]);
	return unionfind[n];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (a > b) {
		unionfind[a] = b;
	}
	else if (a < b) {
		unionfind[b] = a;
	}
}

int main() {
	cin >> n >> m;
	//memset(v, -1, sizeof(v));
	memset(unionfind, -1, sizeof(unionfind));



	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &s, &tmp1, &tmp2);
		if (s == 0) {

			 if (tmp1 > tmp2)
				swap(tmp1, tmp2);
			merge(tmp1, tmp2);
		}
		else if (s == 1) {

				if (find(tmp1) == find(tmp2))
					printf("YES");
				else
					printf("NO");
			
		}
	}



}