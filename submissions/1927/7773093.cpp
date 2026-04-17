#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int N;

priority_queue <int, vector<int>, greater <int>> q;
vector <int> v;

void maxheap(int n) {
	if (q.empty() != 1) {
		v.push_back(q.top());
		q.pop();
	}
	else
		v.push_back(0);

}







int main() {
	cin >> N;
	int tmp;

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (tmp == 0)
			maxheap(tmp);
		else
			q.push(tmp);
	}



	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);

}
