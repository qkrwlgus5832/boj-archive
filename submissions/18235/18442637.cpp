#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <algorithm>
#include <limits.h>
using namespace std;

int N, A, B;

bool ori[500001][20];
bool yukri[500001][20];

void oriRecursion(int location, int depth) {
	int nlocation = location + pow(2, depth);
	if (!(nlocation <= 0 || nlocation >= N + 1)) {
		ori[nlocation][depth + 1] = true;
		oriRecursion(nlocation, depth + 1);
	}

	nlocation = location - pow(2, depth);
	if (!(nlocation <= 0 || nlocation >= N + 1)) {
		ori[nlocation][depth + 1] = true;
		oriRecursion(nlocation, depth + 1);
	}

}

void yukriRecursion(int location, int depth) {
	int nlocation = location + pow(2, depth);
	if (!(nlocation <= 0 || nlocation >= N + 1)) {
		yukri[nlocation][depth + 1] = true;
		yukriRecursion(nlocation, depth + 1);
	}

	nlocation = location - pow(2, depth);
	if (!(nlocation <= 0 || nlocation >= N + 1)) {
		yukri[nlocation][depth + 1] = true;
		yukriRecursion(nlocation, depth + 1);
	}

}

int main() {
	cin >> N >> A >> B;


	oriRecursion(A, 0);
	yukriRecursion(B, 0);

	int result = INT_MAX;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= log2(N); j++) {
			if (ori[i][j] == 1 && ori[i][j] == yukri[i][j]) {
				result = min(result, j);
			}
		}
	}

	if (result == INT_MAX)
		cout << -1;
	else
		cout << result;

	//system("Pause");
}