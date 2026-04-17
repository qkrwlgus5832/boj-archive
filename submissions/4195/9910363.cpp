#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
int unionfind[100001];
int sum[100002] = { 1, };

int T;

int find(int x) {
	if (unionfind[x] < 0)
		return x;

	unionfind[x] = find(unionfind[x]);
	return unionfind[x];
}


int merge(int a, int b) {
	 a = find(a);
	 b = find(b);
	 if (a == b)
		 return sum[a];
	unionfind[a] = b;

	sum[b] = sum[a] + sum[b];
	return sum[b];
}
int main() {
	int T;

	string tmp1, tmp2;
	int F = 0;
	cin >> T;


for (int i = 0; i < T; i++) {
		map <string, int> m;
		scanf("%d", &F);
		memset(unionfind, -1, sizeof(unionfind));
		fill(sum, sum + 100001, 1);


		for (int j = 0; j < F; j++) {
			cin >> tmp1 >> tmp2;
			auto itr = m.find(tmp1);
			if (itr == m.end()) {
				m[tmp1] = m.size();
			}
			itr = m.find(tmp2);
			if (itr == m.end()) {
				m[tmp2] = m.size();
			}
			printf("%d\n", merge(m[tmp1], m[tmp2]));
			
		}
	}

}