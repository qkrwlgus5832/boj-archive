#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int flowergarden[11][11];

bool check[11][11];

int dir[5][2] = { {-1,0}, {1,0}, {0, -1}, {0, 1} ,{0,0} };

int N;

int result = -1;

void settmpcheck(bool check[][11], bool tmpcheck[][11]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmpcheck[i][j] = check[i][j];
		}
	}
}
void setcheck(bool check[][11], bool tmpcheck[][11]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = tmpcheck[i][j];
		}
	}
}

void recursion(int index, int count, int cost) {
	int i = index / N;
	int j = index % N;
	if (index >= 0) {
		for (int i1 = 0; i1 < 5; i1++) {
			int ni = i + dir[i1][0];
			int nj = j + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= N)
				return;

			else if (check[ni][nj] == true)
				return;
			else {
				check[ni][nj] = true;
				cost += flowergarden[ni][nj];
			}
		}
		if (count == 3) {
			if (result == -1)
				result = cost;
			else
				result = min(result, cost);
			return;
		}
	}
	bool tmpcheck[11][11];
	settmpcheck(check, tmpcheck);
	for (int i = index + 2; i < N * N; i++) {
		recursion(i, count+1, cost);
		setcheck(check, tmpcheck);
	}
}




int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> flowergarden[i][j];
		}
	}
	recursion(-2, 0, 0);
	cout << result;
	//system("Pause");

}