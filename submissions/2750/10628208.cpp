#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <limits.h>
using namespace std;


int a[1020];

int M = 5;
void Insertion_sort(int l, int r) {
	for (int i = l + 1; i <= r; i++) {
		int tmp = a[i];
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] > tmp) {
				a[j + 1] = a[j];
			}
			else {
				a[j + 1] = tmp;
				break;
			}
		}
	}

}



void Quicksort(int l, int r) {
	int i, j, v;
	if (r > l && r - l <= M) {
		Insertion_sort(l, r);
		return;
	}

	else if (r > l) {
		v = a[r]; i = l - 1; j = r;
		for (;;) {
			while (a[++i] < v);
			while (a[--j] > v);
			if (i >= j)
				break;
			swap(a[i], a[j]);
		}
		swap(a[i], a[r]);
		Quicksort(l, i - 1);
		Quicksort(i + 1, r);
	}

}

int main() {
	int i;
	a[0] = INT_MIN;
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
	}



	Quicksort(1, N);

	for (int i = 1; i <= N; i++) {
		printf("%d\n", a[i]);
	}
}
