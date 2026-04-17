#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <math.h>
using namespace std;

int n, m;
int input[1001];
int DP[1001];
//int DP[1001][1001];
int NameLength[1001][1001];

int getSparePowLength(int i, int j) {
	return pow(m - (NameLength[i][j] + j - i), 2);
}

int getSpareLength(int i, int j) {
	return NameLength[i][j] + j - i;
}
void deathNote() {
	DP[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (getSpareLength(j + 1,i) > m)
				continue;
			if (i == n) {
				if (DP[i] == -1)
					DP[i] = DP[j];
				else
					DP[i] = min(DP[i], DP[j]);
				continue;
			}
			if (DP[i] == -1) {
				DP[i] = DP[j] + getSparePowLength(j + 1, i);
			}
			else {
				DP[i] = min(DP[i], DP[j] + getSparePowLength(j + 1, i));
			}
		}
	}
}
//void recursion(int i, int j) {
//	if (i == j)
//		DP[i][j] = pow(m - NameLength[i][j], 2);
//
//	if (NameLength[i][j] + j - i <= m)
//		DP[i][j] = getSparePowLength(i, j);
//
//	for (int i1 = i; i1 < j; i1++) {
//
//		if (DP[i][i1] == -1) {
//			recursion(i, i1);
//		}
//		if (NameLength[i1 + 1][j] + j - (i1 + 1) > m)
//			continue;
//
//		if (DP[i][j] == -1) {
//			DP[i][j] = DP[i][i1] + getSparePowLength(i1 + 1, j);
//		}
//		else if (j != n - 1) {
//			DP[i][j] = min(DP[i][j], DP[i][i1] + getSparePowLength(i1 + 1, j));
//		}
//		else {
//			DP[i][j] = min(DP[i][j], DP[i][i1]);
//		}
//	}
//}

int main() {
	cin >> n >> m;
	memset(DP, -1, sizeof(DP));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);

	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (j == i)
				NameLength[i][j] = input[i];
			else
				NameLength[i][j] = (NameLength[i][j - 1] + input[j]);
		}
	}
	deathNote();
	cout << DP[n];
	//recursion(0, n - 1);

	//cout << DP[0][n - 1];

	//system("Pause");
}