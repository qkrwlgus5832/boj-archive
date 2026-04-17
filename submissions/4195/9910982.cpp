#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <string.h>
#include <unordered_map>
#include <vector>
using namespace std;

int unionfind[100001];
int sum[100002] = { 1, };
char c[21];
char b[21];

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
		unordered_map <string, int> unmap;
		scanf("%d", &F);
		memset(unionfind, -1, sizeof(unionfind));
		fill(sum, sum + 100001, 1);


		for (int j = 0; j < F; j++) {
			scanf("%s %s", &b, &c);

			string tmp1 = string(b);
			string tmp2 = string(c);
			auto itr = unmap.find(tmp1);
			if (itr == unmap.end()) {
				unmap.insert(pair<string, int> (tmp1,unmap.size()));
			}
			itr = unmap.find(tmp2);
			if (itr == unmap.end()) {
				unmap.insert(pair<string, int>(tmp2, unmap.size()));


			}
			
			printf("%d\n", merge(unmap[tmp1], unmap[tmp2]));
			
		}
	}

}