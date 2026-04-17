#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int v[1001][3];
int main() {

	int N, K;
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		int tmp1, tmp2, tmp3, tmp4;
		scanf("%d %d %d %d", &tmp1, &tmp2, &tmp3, &tmp4);
		v[tmp1][0] = tmp2;
		v[tmp1][1] = tmp3;
		v[tmp1][2] = tmp4;
	
	}
	
	int rank = 0;
	
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < 3; j++) {
			if (v[i][j] > v[K][j]) {
				rank++;
				break;
			}
			else if (v[i][j] < v[K][j]) {
				break;
			}
		}
	}

	
	cout << rank + 1;

}