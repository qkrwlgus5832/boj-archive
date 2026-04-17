#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int m;
int N1[1000000];

vector <int> v;
vector <int> result;
void  push(int i, int j) {
	
	for (int i1 = i; i1 <= j; i1++)
		v.push_back(N1[i1]);
	
}


int q(int k) {
	int i1 = 0;
	while (i1 != k) {
		for (int i2 = v.size() - 1; i2 > i1; i2--) {
			int a = min(v[i2 - 1], v[i2]);
			int b = max(v[i2 - 1], v[i2]);
			v[i2 - 1] = a;
			v[i2] = b;
		}
		i1 = i1 + 1;
	}
	return v[k - 1];
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
		scanf("%d %d %d", &i, &j, &k);
		push(i, j);
		result.push_back(q(k));
		v.clear();
		
	}
	for (int i = 0; i < m; i++) {
		printf("%d\n", result[i]);
	}
	

}
