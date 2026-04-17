#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

priority_queue <int, vector<int> ,greater<int>>q;

int N;
int K;

int main() {
	cin >> N >> K;
	int a;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		q.push(a);
	}

	for (int i = 0; i < K-1; i++) {
	
		q.pop();
	}

	cout << q.top();


}