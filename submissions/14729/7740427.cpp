#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;
int N;

priority_queue <int, vector<int> , greater<int>> q;


int main() {
	cin >> N;
	float a;



	for (int i = 0; i < N; i++) {
		scanf("%f", &a);
		q.push(a);
	}

	for (int i = 0; i < 7; i++) {
		float b = q.top();
		printf("%.3f\n", b);
		q.pop();
	}

}

	
