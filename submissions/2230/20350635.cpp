#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector <int> v;

int N, M;

int result = INT_MAX;

void twoPointer() {
	int start = 0;
	int end = 0;

	while (1) {
		if (start > end || (start == v.size() - 1 && end == v.size() - 1))
			break;

		int tmp = v[end] - v[start];
		
		if (tmp >= M)
			result = min(result, tmp);

		if (tmp >= M && start  < v.size() -1) {
			start++;
		}
		else if (end < v.size() -1){
			end++;
		}
		else if (end == v.size() - 1) {
			start++;
		}
	}

}
int main() {
	cin >> N >> M;

	v.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	
	sort(v.begin(), v.end());
	twoPointer();
	cout << result;
	//system("Pause");

}