#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

vector <int> v;

int N, M;

bool isAnswer(int x) {
	int money = x;
	int count = 1;
	for (int i = 0; i < N; i++) {
		if (x < v[i])
			return false;

		if (money - v[i] < 0) {
			money = x;
			money -= v[i];
			count++;
		}
		else {
			money -= v[i];
		}
	}

	if (count <= M)
		return true;
	return false;
}


int binary_search(long long start, long long end) {

	if (start == end) {
		return start;
	}
	else if (start + 1 == end) {
		if (isAnswer(start))
			return start;
		else
			return end;
	}
	if (isAnswer((start + end) / 2) == false) {
		return binary_search((start + end) / 2 + 1, end);
	}

	return binary_search(start, (start + end) / 2);

}

int main() {

	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	cout << binary_search(0, 10000 * 100000);
	//system("Pause");
}