#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int N;
int input[21][21];


int getFifthCount(int x, int y,int d1, int d2, bool check[21][21]) {
	for (int i = 0; i <= d1; i++) {
		check[x + i][y - i] = true;
		
	}
	for (int i = 0; i <= d2; i++) {
			check[x + i][y + i] = true;
			check[x + d1 + i][y - d1 + i] = true;
	}
	
	for (int i = 0; i <= d1; i++) {
		check[x + d2 + i][y + d2 - i] = true;
	}
	int count = 0;
	for (int i = 1; i <= N; i++) {
		int lastindex = -1;
		for (int j = 1; j <= N; j++) {
			if (check[i][j] == true) {
				if (lastindex == -1) {
					lastindex = j;
					count += input[i][j];
				}
				else {
					for (int j1 = lastindex + 1; j1 <= j; j1++) {
						count += input[i][j1];
						check[i][j1] = true;
					}
					
					break;
				}
			}
		}
	}
	return count;
}

int getSectionCount(int rstart, int rend, int cstart, int cend, bool check[21][21]) {
	int count = 0;
	for (int r = rstart; r <= rend; r++) {
		for (int c = cstart; c <= cend; c++) {
			if (check[r][c] != true) {
				count += input[r][c];
			}
		}
	}
	return count;
}
int garymandering(int x, int y, int d1, int d2) {
	bool check[21][21] = { false, };
	
	int fifthCount = getFifthCount(x, y, d1, d2, check);
	int maxCount = fifthCount;
	int minCount = fifthCount;

	int firstCount = getSectionCount(1, x+d1 - 1, 1, y, check);
	
	maxCount = max(maxCount, firstCount);
	minCount = min(minCount, firstCount);
	int secondCount = getSectionCount(1, x + d2, y + 1, N, check);

	maxCount = max(maxCount, secondCount);
	minCount = min(minCount, secondCount);
	int thirdCount = getSectionCount(x+d1, N, 1, y -d1 + d2 -1, check);


	maxCount = max(maxCount, thirdCount);
	minCount = min(minCount, thirdCount);
	int fourthCount = getSectionCount(x + d2 + 1, N, y -d1 + d2, N, check);

	maxCount = max(maxCount, fourthCount);
	minCount = min(minCount, fourthCount);

	return maxCount - minCount;
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &input[i][j]);
		}
	}
	int result = INT_MAX;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d2 = 1; d2 <= N - y; d2++) {
				for (int d1 = 1; d1 <= N - x - d2; d1++) {
					result = min(result,garymandering(x, y, d1, d2));
				}
			}
		}
	}
	cout << result;
}