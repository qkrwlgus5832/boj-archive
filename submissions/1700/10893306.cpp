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


int indexd(int i , int value) {
	for (int i1 = i+1; i1 < v.size(); i1++) {
		if (v[i1] == value) {
			return i1;
		}
	}
}



void max1(int index) {
	int maxd = indexd(index, dq.at(0));
	int maxi = 0;
	for (int i = 0; i < dq.size(); i++) {
		if (N1[dq.at(i)] == 0) {
			maxd = N1[dq.at(i)];
			maxi = i;
			break;
		}
		else if (maxd < indexd(index, dq.at(i))) {
			maxd = indexd(index, dq.at(i));
			maxi = i;
		}
	}
	check[dq.at(maxi)] = false;
	dq.erase(dq.begin() + maxi);


}
int main() {

	int N;
	int K;
	cin >> N >> K;
	int tmp;


	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);
		N1[tmp] = i;
		v.push_back(tmp);

	}

	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (check[v[i]] == false) {
			if (dq.size() == N) {
				max1(i);
				count++;
			}
			dq.push_back(v[i]);
			check[v[i]] = true;
		}
		if (i == N1[v[i]])
			N1[v[i]] = 0;
	}
	cout << count;

}