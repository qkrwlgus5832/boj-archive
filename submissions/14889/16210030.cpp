#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int N;
int graph[21][21];
bool check[21];
int result = INT_MAX;

int checkcapacity(bool flag) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (check[i] == flag) {
			for (int j = 0; j < N; j++) {
				if (check[j] == flag)
					count += graph[i][j];
			}
		}
	}
	return count;
}
void recursion(int target, int count) {
	if (count == target) {
		result = min(result, abs(checkcapacity(true) - checkcapacity(false)));
	}
	for (int i = 0; i < N; i++) {
		if (check[i] == false) {
			check[i] = true;
			recursion(target, count + 1);
			check[i] = false;
		}
	}
}


int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	recursion(N / 2, 0);
	//for (int i = 1; i <= N / 2; i++) {
	//	recursion(i, 0);
	//}
	cout << result;
	//system("Pause");
}