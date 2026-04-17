#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int m;
int N1[1000000];
vector <int > v2;

void  Q(int i, int j, int k) {
	vector <int> v;
	
	for (int i1 = i; i1 <= j; i1++) {
		v.push_back(N1[i1]);
	}
	
	sort(v.begin(), v.end());
	
	v2.push_back(v[k - 1]);
}


int main() {
	cin >> n;
	cin >> m;
	
	int i;
	int j;
	int k;

	for (int i = 1; i <= n; i++) {
		scanf("%d ", &N1[i]);
	}




	for (int i1 = 0; i1 < m; i1++) {
		cin >> i >> j >> k;
		Q(i, j, k);
		
	}
	for (int i = 0; i < m; i++) {
		printf("%d\n", v2[i]);
	}


}