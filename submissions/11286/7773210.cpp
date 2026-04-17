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
priority_queue <int> q2;

vector <int> v;

void maxheap() {
	if (q.empty() != 1 && q2.empty() != 1) {
		if (abs(q.top()) < abs(q2.top())) {
			v.push_back(q.top());
			q.pop();
		}
		else {
			v.push_back(q2.top());
			q2.pop();
		}

	}
	else if (q.empty() != 1) {
		v.push_back(q.top());
		q.pop();
	}
	else if (q2.empty() != 1) {
		v.push_back(q2.top());
		q2.pop();
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
			maxheap();
		else if (tmp > 0)
			q.push(tmp);
		else if (tmp < 0)
			q2.push(tmp);
	}


	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);
		
}
