#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int M;
int cards[101];
int result = 0;

void recursion(int index, int count , int value) {
	if (value > M)
		return;
	if (count == 3) {
		result = max(result, value);
		return;
	}
	for (int i = index; i < N; i++) {
		recursion(i + 1, count + 1, value + cards[i]);
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}
	recursion(0, 0, 0);
	cout << result;
	//system("Pause");
}