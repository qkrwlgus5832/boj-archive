#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector <pair <int, int>> v;
int result = 0;

int calculate(bool check[9]) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (check[i])
			count++;
	}
	return count;
}
void recursion(int i, bool check[9]) {
	if (i == N) {
		result = max(result, calculate(check));
		return;
	}
	bool flag = false;
	for (int index = 0;  index < N; index++) {
		if (i == index)
			continue;
		if (check[i] == false && check[index] == false) {
			v[i].first -= v[index].second;
			v[index].first -= v[i].second;

			if (v[i].first <= 0) {
				check[i] = true;
			}
			if (v[index].first <= 0) {
				check[index] = true;

			}
			flag = true;
			recursion(i + 1, check);
			v[i].first += v[index].second;
			v[index].first += v[i].second;
			check[i] = false;
			check[index] = false;
			
		}
	}
	if (flag == false) {
		recursion(i + 1, check);
	}
}
int main() {

	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a, b));
	}
	bool check[9] = { false, };
	recursion(0, check);
	cout << result;
	//system("Pause");
}