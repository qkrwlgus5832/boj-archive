#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <hash_map>
#include <vector>
using namespace std;
using namespace stdext;
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
		hash_map <string, int> has1;
		scanf("%d", &F);
		memset(unionfind, -1, sizeof(unionfind));
		fill(sum, sum + 100001, 1);


		for (int j = 0; j < F; j++) {
			cin >> tmp1 >> tmp2;
			auto itr = has1.find(tmp1);
			if (itr == has1.end()) {
				has1.insert(hash_map<string, int> ::value_type(tmp1, has1.size()));
			}
			itr = has1.find(tmp2);
			if (itr == has1.end()) {
				has1.insert(hash_map<string, int> ::value_type(tmp2, has1.size()));

			}
			
			printf("%d\n", merge(has1.lower_bound(tmp1)->second, has1.lower_bound(tmp2)->second));
			
		}
	}

}