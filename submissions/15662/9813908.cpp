#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <deque>
#include <vector>
#include <math.h>
#include <memory.h>
using namespace std;

vector <deque <int> > v;
bool check[1001];
void recursion(int num, int direction) {
	deque <int> tmp = v[num];
	check[num] = true;

	if (num - 1 >= 0 && check[num - 1] == false && v[num - 1].at(2) != v[num].at(6)) {
		recursion(num - 1, direction * -1);
	}
	if (num + 1 <= v.size()-1 && check[num + 1] == false && v[num].at(2) != v[num + 1].at(6)) {
		recursion(num + 1, direction * -1);
	}

	if (direction == 1) {
		int t = tmp.back();
		tmp.pop_back();
		tmp.push_front(t);
		v[num] = tmp;
	}
	else if (direction == -1) {
		int t = tmp.front();
		tmp.pop_front();
		tmp.push_back(t);
		v[num] = tmp;
	}
}




int main() {
	int tmp;
	int K;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		deque <int> q1;
		for (int i = 0; i < 8; i++) {
			scanf("%1d", &tmp);
			q1.push_back(tmp);
		}
		v.push_back(q1);

	}


	cin >> K;


	int num, direction;
	for (int i = 0; i < K; i++) {
		cin >> num >> direction;
		recursion(num - 1, direction);
		memset(check, false, sizeof(check));
	}
	int result = 0;
	for (int i = 0; i < T; i++) {

		if (v[i].at(0) == 1) {
			result = result + 1;
		}
	}
	cout << result;
}