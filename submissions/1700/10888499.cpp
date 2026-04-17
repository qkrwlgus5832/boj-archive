#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;


int N1[101];
vector <int> v;
deque <int> dq;

bool check[101];

void min1() {
	int mind = N1[dq.at(0)];
	int mini = 0;
	for (int i = 0; i < dq.size(); i++) {
		if (mind > N1[dq.at(i)]) {
			mind = N1[dq.at(i)];
			mini = i;
		}
	}
	check[dq.at(mini)] = false;
	dq.erase(dq.begin() + mini);
	

}
int main(){

	int N;
	int K;
	cin >> N >> K;
	int tmp;


	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);
		N1[tmp]++;
		v.push_back(tmp);
	}

	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (check[v[i]] == false) {
			if (dq.size() == N) {
				min1();
				count++;
			}
			dq.push_back(v[i]);
			check[v[i]] = true;
		}
		N1[v[i]] = N1[v[i]] - 1;
	}
	cout << count;

}