#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> N1;

vector <pair <int, int>> v;

int N;
int main() {
	cin >> N;
	int tmp;

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		N1.push_back(tmp);
		v.push_back(make_pair(tmp, i));
	}


	sort(v.begin(), v.end());



	int result = 0;


	for (int i = 0; i < v.size(); i++) {
		result = max(result, v[i].second - i);
	}
	cout << result + 1;


}