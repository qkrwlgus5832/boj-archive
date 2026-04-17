#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector <int> v[101];
bool check[101];


int N, M;
int tmp1, tmp2;
int result = 0;
void recursion(int i) {
	for (int i1 = 0; i1 < v[i].size(); i++) {
		int a = v[i][i1];
		if (check[a] == false) {
			if (a!=1)
			result++;
			check[a] = true;
			recursion(a);		
		}
	}
	
}


int main() {
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &tmp1, &tmp2);
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}

	recursion(1);
	cout << result;
}