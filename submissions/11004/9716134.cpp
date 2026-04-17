#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v;


int N;
int K;


int main() {
	cin >> N >> K;
	int a;

	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		v.push_back(a);
	}


	sort(v.begin(), v.end());



	cout << v[K-1] << endl;

}