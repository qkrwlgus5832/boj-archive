#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, S;

vector <int> v;

int main() {
	cin >> N >> S;
	int tmp;
	v.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 1; i < v.size(); i++) {
		v[i] = v[i - 1] + v[i];
	}

	int left = 0;
	int right = 0;

	int result = INT_MAX;


	while (1) {
		if (left >= v.size() || right >= v.size())
			break;
		if (v[right] - v[left] > S) {
			result = min(result, right - left);
			left++;

		}
		else if (v[right] - v[left] == S) {
			result = min(result, right - left);
			right++;


		}
		else if (v[right] - v[left] < S) {
			right++;
		}
	}
	if (result != INT_MAX)
		cout << result;
	else
		cout << 0;

	//system("Pause");
}