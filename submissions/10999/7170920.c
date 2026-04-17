#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int N = 0;
int M = 0;
int K = 0;
long long node[1000001];
long long tree[9000001];
long long K1[30001];
int p = 1;
int count = 0;
int a = 0;
int b = 0;
int c = 0;
int i = 0;
int A2[300001];
int B2[100001];
int C2[100001];
int D2[100001];





long long sum(int a, int b, int node, int x, int y) {
	if (x > b || y < a)
		return 0;
	else if (x >= a && y <= b)
		return tree[node];
	else
		return sum(a, b, node * 2, x, (x + y) / 2) + sum(a, b, (node * 2) + 1, ((x + y) / 2) + 1, y);
}



int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &node[i]);
	}
	for (int j = 0; j < M + K; j++) {
		scanf("%d", &A2[j]);
		if (A2[j]==1)
		scanf("%d %d %d", &B2[j], &C2[j], &D2[j]);
		else
			scanf("%d %d", &B2[j], &C2[j]);
	}

	
	while (p < N) {
		p = p * 2;
	}

	for (int i = p; i < p + N; i++) {
		tree[i] = node[i - p];
	}
	for (int i = p + N; i < 2 * p; i++) {
		tree[i] = 0;
	}

	for (int j = p - 1; j >= 1; j--)
		tree[j] = tree[j * 2] + tree[j * 2 + 1];


	for (int j1 = 0; j1 < M + K; j1++) {

		if (A2[j1] == 1)
		{
			for (int i = B2[j1]; i <= C2[j1]; i++) {
				tree[p + i - 1] = tree[p + i - 1] + D2[j1];
			}
			if (C2[j1] - B2[j1] % 2 == 0) {
				for (int i3 = B2[j1]; i3 <= C2[j1]; i3 = i3 + 2) {
					for (int j3 = (i3 + p - 1) / 2; j3 >= 1; j3 = j3 / 2)
						tree[j3] = tree[j3 * 2] + tree[j3 * 2 + 1];
				}
			}
			else
				for (int i3 = B2[j1]; i3 <= C2[j1]; i3 = i3 + 2) {
					for (int j3 = (i3 + p - 1) / 2; j3 >= 1; j3 = j3 / 2)
						tree[j3] = tree[j3 * 2] + tree[j3 * 2 + 1];
				}
			for (int j3 = (C2[j1] + p - 1) / 2; j3 >= 1; j3 = j3 / 2)
				tree[j3] = tree[j3 * 2] + tree[j3 * 2 + 1];

		}
		else if (A2[j1] == 2)
		{
			if (B2[j1] == C2[j1])
				K1[count] = tree[B2[j1] + p - 1];
			else
				K1[count] = sum(B2[j1], C2[j1], 1, 1, p);

			count++;
		}


	}
	for (int q = 0; q < K; q++)
		printf("%lld\n", K1[q]);




}
