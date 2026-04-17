#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int A[51][51];
int B[51][51];
int N, M;

int greedy() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				for (int i1 = i; i1 < i + 3; i1++) {
					for (int j1 = j; j1 < j + 3; j1++) {
						A[i1][j1] = !A[i1][j1];
					}
				}
				result++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j])
				return -1;
		}
	}
	return result;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &A[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &B[i][j]);
		}
	}


	cout << greedy();

}