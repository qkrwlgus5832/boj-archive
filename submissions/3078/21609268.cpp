#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, K;
	
vector <int> v[21];
long long result = 0;

void twoPointer() {
	int start = 0;
	int end = 1;
	int count = 1;

	for (int i = 1; i <= 20; i++) {
		while (1) {
			if (start >= v[i].size() || end >= v[i].size()) {
				start = 0;
				end = 1;
				result += count * (count - 1) / 2;
				count = 1;
				break;
			}
			if (v[i][end] - v[i][start] <= K) {
				count++;
				end++;
			}
			else {
				start++;
				result += count * (count - 1) / 2;
				count = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> K;

	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v[input.size()].push_back(i + 1);
	}


	twoPointer();
	cout << result;
	//system("Pause");
}