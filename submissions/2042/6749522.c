#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int N=0;
int M=0;
int K=0;
int node[1000001];
int tree[9000000];
int K1[10001];
int p = 1;

int a = 0;
int b = 0;
int c = 0;
int i = 0;
int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i1 = 0; i1 < N; i1++) {
		scanf("%d\n", &node[i1]);
	}
	int *A2 = malloc(sizeof(int)*(K + M));
	int *B2 = malloc(sizeof(int)*(K + M));
	int *C2 = malloc(sizeof(int)*(K + M));


	for (int j1 = 0; j1 < M + K; j1++) {
		scanf("%d %d %d", &A2[j1], &B2[j1], &C2[j1]);
	}


	while (p < N) {
		p = p * 2;
	}
	for (int i = p; i < p + N; i++) {
		tree[i] = node[i - p];
	}
	for (int i3 = p + N; i3 < 2 * p; i3++) {
		tree[i3] = 0;
	}

	for (int j = p - 1; j >= 1; j--)
		tree[j] = tree[j * 2] + tree[j * 2 + 1];


	for (int j1 = 0; j1 < M + K; j1++) {
	
		if (A2[j1] == 1)
		{
			tree[p + B2[j1] - 1] = C2[j1];
			for (int j3 = p - 1; j3 >= 1; j3--)
				tree[j3] = tree[j3 * 2] + tree[j3 * 2 + 1];

		}



		else if (A2[j1] == 2)
		{

			if ((B2[j1] + p - 1) % 2 == 1) {
				K1[i] = tree[B2[j1] + p - 1];
				for (int q2 = B2[j1] + p; q2 <= C2[j1] + p - 1; q2 = q2 + 2) {
					if (q2 == C2[j1] + p - 1)
						K1[i] = K1[i] + tree[q2];
					else
						K1[i] = K1[i] + tree[q2 / 2];
				}
				i++;
			}



			else {
				K1[i] = 0;
				for (int q2 = B2[j1] + p - 1; q2 <= C2[j1] + p - 1; q2 = q2 + 2) {
					if (q2 == C2[j1] + p - 1)
						K1[i] = K1[i] + tree[q2];
					else
						K1[i] = K1[i] + tree[q2 / 2];
				}
				i++;
			}

		}


	}
	for (int q = 0; q < K; q++)
		printf("%d\n", K1[q]);


	free(A2);
	free(B2);
	free(C2);

}

