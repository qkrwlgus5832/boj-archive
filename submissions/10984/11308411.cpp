#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;


int T;
int N;
int C;
 char s[4];



int main() {

	cin >> T;


	for (int i = 0; i < T; i++) {
		float result = 0;
		int count = 0;
		scanf("%d", &N);
		for (int i1 = 0; i1 < N; i1++) {
			scanf("%d %s", &C, s);
			string tmp(s);
			if (tmp.size() == 3) {
				result += ((tmp[0] - '0') * 10 + (tmp[2] - '0')) * C;
			}
			else {
				result += ((tmp[0] - '0') * 10) * C;
			}



			count += C;
		}


		printf("%d %.1f\n", count, (result / count) / 10 + exp(-9));
	}
	
}