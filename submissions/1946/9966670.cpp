#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N;
int tmp1, tmp2;
vector <pair <int, int>> v;
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &tmp1, &tmp2);
			v.push_back(make_pair(tmp1, tmp2));

		}

		sort(v.begin(), v.end());
		int count = 0;
		for (int i = 1; i < v.size(); i++) {
			for (int j = i-1; j >=0; j--) {
				if (v[i].second > v[j].second) {
					count++;
					break;
				}
				
			}
		}

		printf("%d\n", N- count);
		v.clear();

	}
}