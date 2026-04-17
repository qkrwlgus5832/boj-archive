#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N, M;
int N1[10];
vector <int> v;
void recursion() {

	if (v.size() == M) {
		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
		printf("\n");
		v.pop_back();
		return;
	}

	for (int i = 0; i < N; i++) {
		v.push_back(N1[i]);
		recursion();
	}
	if (v.size()>=1)
	v.pop_back();
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%d", &N1[i]);

	sort(N1, N1+N);

	recursion();


}