#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;


vector <int> input;

int maxResult = 0;

void DFS(int potion, int result, int current, int index) {
	if (index == input.size()) {
		maxResult = max(result, maxResult);
		return;
	}
	if (input[index] != current) {
		if (potion > 0) {
			DFS(potion - 1, result + 1, !current, index + 1);
		}
		DFS(potion, result, current, index + 1);
	}
	else {
		DFS(potion, result + 1, current, index + 1);
	}
}

int main() {

	int T, W;
	
	cin >> T >> W;

	input.resize(T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &input[i]);
		input[i]--;
	}

	DFS(W, 0, 0, 0);
	cout << maxResult;

	//system("Pause");
}
