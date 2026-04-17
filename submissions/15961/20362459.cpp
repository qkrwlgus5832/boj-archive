#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N, d, k, c;

set <int> kindCheck;
int kindCount[3001];
vector <int> input;
int result = 0;

void init() {
	for (int i = 0; i < k; i++) {
		if (input[i] != c) {
			kindCheck.insert(input[i]);
			kindCount[input[i]]++;
		}
	}
}

void slidingWindow() {
	init();
	
	int start = 0;
	int end = start + k;

	while (1) {
		if (start != 0 && start % input.size() == 0) {
			break;
		}
		if (--kindCount[input[start]] == 0) {
			kindCheck.erase(input[start]);
		}

		if (++kindCount[input[end % input.size()]] == 1) {
			if (input[end % input.size()] != c)
				kindCheck.insert(input[end % input.size()]);
		}
		result = max(result, (int) kindCheck.size());
		start++;
		end++;
	}
}

int main() {
	cin >> N >> d >> k >> c;

	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		input.push_back(tmp);
	}

	slidingWindow();

	cout << result + 1;
	//system("Pause");
}