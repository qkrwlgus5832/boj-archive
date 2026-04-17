#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>


using namespace std;


int N;
priority_queue <int, vector <int>, greater<int>> minheap;
priority_queue <int, vector <int>, less<int>> maxheap;

int main() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (maxheap.size() == 0) {
			maxheap.push(tmp);
			printf("%d\n", maxheap.top());
			continue;
		}
		if (maxheap.top() <= tmp) {
			minheap.push(tmp);
			while (minheap.size() > maxheap.size()) {
				maxheap.push(minheap.top());
				minheap.pop();
			}
		}
		if (maxheap.top() > tmp) {
			maxheap.push(tmp);
			while (maxheap.size() > minheap.size() + 1) {
				minheap.push(maxheap.top());
				maxheap.pop();
			}

		}
		printf("%d\n", maxheap.top());
	}
	//system("Pause");
}