#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int N;
int M;
int arr[101][101];



int check(int n) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
		
			if (i + n - 1 < N && arr[i + n - 1][j] == arr[i][j]) {
				if (j + n - 1 < M && arr[i][j + n - 1] == arr[i][j]) {
					if (arr[i + n - 1][j + n - 1] == arr[i][j]) {
						return n;
					}
				}
			}

		}
	}
	return 0;
}

int main(void) {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	int tmp;
	if (N <= M) {
		tmp = N;

	}
	else {
		tmp = M;
	}
	int f = 0;
	int result = 0;





	for (int i = tmp; i >= 2; i--) {
		
		if (check(i) >=2) {
			result = check(i);
			f = 1;
			break;
		}
	}

	if (f == 1) {
		cout << result*result;
	}

	else {
		cout << 1;
	}

}
