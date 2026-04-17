#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N1[21];
int N, S;

vector <int> v;

int result = 0;

bool caculate() {
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		result += N1[v[i]];
	}
	if (result == S)
		return true;
	else
		return false;
}
void recursion(int i1) {
	if (i1 != 0 && caculate() == true) {
		result++;

	}


	for (int i = i1; i < N; i++) {
		v.push_back(i);
		recursion(i + 1);
	}
	if (v.size() >= 1)
		v.pop_back();
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		scanf("%d", &N1[i]);

	}

	recursion(0);

	cout << result;
	//system("Pause");
}