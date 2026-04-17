#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

int N;

priority_queue <int, vector<int>, greater <int>> q;

vector <int> v;

int mincard() {
	int result = 0;
	while (q.size() != 1) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		result = result + a + b;
		q.push(a + b);
	}
	return result;
}







int main() {
	cin >> N;
	int tmp;

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
	
		q.push(tmp);
	
	}

	cout << mincard();


		
}
