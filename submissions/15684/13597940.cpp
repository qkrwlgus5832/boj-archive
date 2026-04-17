#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, H;

int map[11][31];

bool checkmap[11][31];

int result = -1;

bool check() {
	for (int i = 1; i <= N; i++) {
		int ladder = i;
		for (int j = 1; j <= H; j++) {
			if (map[ladder][j] != 0) {
				ladder = map[ladder][j];
			}
		}
		if (ladder != i)
			return false;
	}
	return true;
}

void setmap(int map2[][31], int willsetmap[][31]) {
	for (int i = 1; i <= N; i++) {
		willsetmap[i][0] = 0;
		for (int j = 1; j <= H; j++) {
			willsetmap[i][j] = map2[i][j];
		}
	}
}

void recursion(int i, int j, int count) {
	if (count == 3) {
		if (check() == true) {
			if (result == -1)
				result = count;
			else
				result = min(result, count);
		}
		return;
	}
	else {
		if (check() == true) {
			if (result == -1)
				result = count;
			else
				result = min(result, count);
			return;
		}
	}
	int backmap[11][31];
	setmap(map, backmap);

	for (int i1 = (H * (i-1)) + j; i1 <= (N - 1)* H; i1++) {
		int Nindex = i1 / H + 1;
		int Hindex = i1 % H;
		if (Hindex == 0) {
			Nindex--;
			Hindex = H;
		}
		if (checkmap[Nindex][Hindex] == true || checkmap[Nindex+1][Hindex] == true || map[Nindex][Hindex] > 0 || map[Nindex+1][Hindex] > 0)
			continue;
		map[Nindex][Hindex] = Nindex + 1;
		map[Nindex + 1][Hindex] = Nindex;
		recursion(Nindex, Hindex, count + 1);
		map[Nindex][Hindex] = 0;
		map[Nindex + 1][Hindex] = 0;
		/*map[Nindex][Hindex] = 0;
		map[Nindex + 1][Hindex] = 0;*/
	}

	
}

int main() {
	cin >> N >> M >> H;
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		map[b][a] = b + 1;
		map[b + 1][a] = b;
		checkmap[b][a] = true;
		checkmap[b + 1][a] = true;
	}

	recursion(1, 1, 0);

	cout << result;

	//system("Pause");
}