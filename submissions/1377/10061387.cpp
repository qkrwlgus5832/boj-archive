#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> N1;

vector <int> v;

int N;
int main() {
	cin >> N;
	N1.resize(500001);
	v.push_back(-1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &N1[i]);
	}

	printf("%d", N1[N]);




}