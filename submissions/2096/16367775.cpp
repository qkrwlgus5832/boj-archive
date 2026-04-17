#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <limits.h>
using namespace std;

int N;


void setBefValue(int tmpcol[], int befcol[]) {
	for (int i = 0; i < 3; i++)
		befcol[i] = tmpcol[i];
}
int main() {
	cin >> N;
	int col1, col2, col3;
	int befmaxcol[3];
	int befmincol[3];
	int result_MAX = 0;
	int result_MIN = INT_MAX;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &befmaxcol[i]);
		befmincol[i] = befmaxcol[i];
	}

	for (int i = 1; i < N; i++) {
		
		scanf("%d %d %d", &col1, &col2, &col3);
		int tmpcol[3];
		tmpcol[0] = max(col1 + befmaxcol[1], col1 + befmaxcol[0]);
		tmpcol[1]= max(befmaxcol[0] + col2, befmaxcol[1] +  col2);
		tmpcol[1] = max(tmpcol[1], befmaxcol[2] + col2);
		tmpcol[2] = max(befmaxcol[1] + col3, befmaxcol[2] + col3);
		setBefValue(tmpcol, befmaxcol);
		
		tmpcol[0] = min(col1 + befmincol[0], col1 + befmincol[1]);
		tmpcol[1] = min(befmincol[0] + col2, befmincol[1] + col2);
		tmpcol[1] = min(tmpcol[1], befmincol[2] + col2);
		tmpcol[2] = min(befmincol[1] + col3, befmincol[2] + col3);
		setBefValue(tmpcol, befmincol);
	}

	for (int i = 0; i < 3; i++) {
		result_MAX = max(result_MAX, befmaxcol[i]);

	}
	for (int i = 0; i < 3; i++) {
		result_MIN = min(result_MIN, befmincol[i]);

	}

	cout << result_MAX << " " << result_MIN;
	//system("Pause");
}
	
	
