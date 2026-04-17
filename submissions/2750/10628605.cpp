#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;


int a[1001];

int N;
void heapify(int h, int m) {

	int v = a[h];
	int j;
	for (j = 2 * h; j <= m; j = j * 2) {
		if (j < m && a[j] < a[j + 1])
			j = j + 1;
		if (v >= a[j])
			break;
		else
			a[j / 2] = a[j];

	}
	a[j / 2] = v;
}

void Heapsort(int N) {
	for (int i = N / 2; i >= 1; i--) {
		heapify(i, N);
	}
	for (int i = N; i >= 2; i--)
	{
		swap(a[1], a[i]);
		if (i!=2)
		heapify(1, i-1);

	}
}




int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
	}

	Heapsort(N);

	for (int i = 1; i <= N; i++)
		printf("%d\n", a[i]);

}