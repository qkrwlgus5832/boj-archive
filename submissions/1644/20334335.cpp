#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

vector <int> v;

int N;
int result = 0;

bool check[4000001];

void getPrimeNumber(int x) {
	check[1] = true;
	for (int i = 2; i <= x; i++) {
		for (int j = i + i; j <= x; j += i) {
			check[j] = true;
		}
	}
	for (int i = 1; i <= x; i++) {
		if (check[i] == false) {
			v.push_back(i);
		}
	}
}

void twoPointer() {
	if (v.size() == 0)
		return;
	int start = 0;
	int end = 0;
	int value = v[0];
	while (1) {
		if (start == v.size() || start > end)
			break;
		if (value <= N) {
			if (value == N)
				result++;
			end++;
			if (end == v.size())
				break;
			value += v[end];
		}
		else {
			value -= v[start];
			start++;
			
		}

	}
}
int main() {
	cin >> N;

	
	getPrimeNumber(N);

	
	twoPointer();
	cout << result;
	//system("Pause");


}