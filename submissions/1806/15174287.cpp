#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;

vector <int> v;

int main() {
	cin >> N >> S;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 1; i < N; i++) {
		v[i] = v[i - 1] + v[i];
	}

	int left = 0;
	int right = 0;

	int result = INT_MAX;

	if (v[0] >= S)
		result = 1;

	while (1) {
		if (left >= v.size() || right  >= v.size())
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

	cout << result;
	//system("Pause");
}