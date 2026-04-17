#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N1[500001];
int N2[500001];
vector <pair<int,int>> v;
int N;
int H;
int main() {
	cin >> N >> H;
	
	int tmp;

	long long tjrtns = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (i % 2 == 0) {	
			N1[tmp]++;
			tjrtns++;
		}
		else {
			N2[tmp]++;
		}
	}
	
	 tmp = 0;
	for (int i = 1; i <= H; i++) {
		tmp = tmp + N2[H - i + 1];
		v.push_back(make_pair(tjrtns + tmp, i));
		tjrtns = tjrtns - N1[i];
	}


	sort(v.begin(), v.end());



	printf("%d ", v[0]);



	
	int result = 0;
	for (int i = 0; i < v.size(); i++) {

		if (v[i].first == v[0].first)
			result++;

	}

	printf("%d", result);
	
}