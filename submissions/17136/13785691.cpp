#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int coloredpaper[10][10];

int result = -1;

int papercount[5] = { 5,5,5,5,5 };

void setZeroOrOne(int i, int j, int i1, int value) {
	for (int i2 = 0; i2 <= i1; i2++) {
		for (int j2 = 0; j2 <= i1; j2++) {
			coloredpaper[i + i2][j + j2] = value;

		}
	}
}

int paperCheck(int i, int j, int i1) {
	for (int i2 = 0; i2 <= i1; i2++) {
		for (int j2 = 0; j2 <= i1; j2++) {
			if (coloredpaper[i + i2][j + j2] == 0)
				return 0;
		}
	}
	return 1;
}

int paperSuccessCheck() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (coloredpaper[i][j] == 1) {
				return 0;
			}
		}
	}
	return 1;
}
void recursion(int tmpindex , int count) {
	if (result != -1 && count >= result)
		return;

	if (paperSuccessCheck() == 1) {
		if (result == -1) {
			result = count;
		}
		else {
			result = min(result, count);
		}
		return;
	}


	for (int index = tmpindex; index < 100; index++) {
		int i = index / 10;
		int j = index % 10;
			if (coloredpaper[i][j] == 1) {

				for (int i1 = 4; i1 >= 0; i1--) {
					if (i + i1 >= 10 || j + i1 >= 10)
						continue;
					else if (papercount[i1] == 0)
						continue;

					if (paperCheck(i, j, i1)) {
						setZeroOrOne(i, j, i1, 0);
						papercount[i1]--;
						recursion(i * 10 + j + 1, count + 1);
						setZeroOrOne(i, j, i1, 1);
						papercount[i1]++;
					}
				}
				break;
			}
	}


}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &coloredpaper[i][j]);
		}
	}

	recursion(0,  0);
	cout << result;
	//system("Pause");
}