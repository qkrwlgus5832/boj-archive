#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


int N;
int M;
int arr[501][501];

int count1 = 0;

void recursion(int i,int j) {
	if (i == M - 1 && j == N - 1) {
		count1++;
		return;
	}

	if (j + 1 <= N - 1 && arr[i][j + 1] < arr[i][j]) {

		recursion(i, j + 1);
	}
	if (j - 1 <= N - 1 && arr[i][j - 1] < arr[i][j]) {
		recursion(i, j - 1);
	}
	if (i - 1 >= 0 && arr[i - 1][j] < arr[i][j]) {
		recursion(i - 1, j);
	}
	if (i + 1 <= M - 1 && arr[i + 1][j] < arr[i][j]) {
		recursion(i + 1, j);

	}

}
	




int main() {


	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}


	recursion(0, 0);
	cout << count1;

}