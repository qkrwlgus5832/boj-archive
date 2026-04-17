#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int tictactoe[4][4];


bool tictactoe2(int player) {

	for (int i = 1; i <= 3; i++) {
		int f = 0;
		for (int j = 1; j <= 3; j++) {
			if (tictactoe[j][i] != player) {
				f = 1;
				break;
			}
		}
		if (f == 0) {
			return true;
		}
	}


	for (int i = 1; i <= 3; i++) {
		int f = 0;
		for (int j = 1; j <= 3; j++) {
			if (tictactoe[i][j] != player) {
				f = 1;
				break;
			}
		}
		if (f == 0) {
			return true;
		}
	}

	int f = 0;
	for (int i = 0; i < 3; i++) {
	
		if (tictactoe[1 + i][1 + i] != player) {
			f = 1;
			break;
		}
	
	}
	if (f == 0) {
		return true;
	}
	f = 0;
	for (int i = 0; i < 3; i++) {
		if (tictactoe[1 + i][3 - i] != player) {
			f = 1;
			break;
		}



	}

	if (f == 0) {
		return true;
	}
	
	return false;
	
}

int main() {
	int N;
	cin >> N;

	int a, b;


	int result = 0;
 	for (int i = 0; i < 9; i++) {
		scanf("%d %d", &a, &b);
		tictactoe[a][b] = N;
		if (result ==0 && tictactoe2(N)) {
			printf("%d\n", N);
			result = 1;
		}
	
		if (N == 2) {
			N = 1;
		}
		else {
			N = 2;
		}

	}
	if (result == 0) {
		printf("0");
	}


}