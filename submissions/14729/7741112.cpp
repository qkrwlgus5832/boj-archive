#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
int N;


vector <float> v;
vector <float> v2;
int main() {
	cin >> N;
	float a;
	
	int a1 = 0;
	if (N >= 1000000) {
		for (int i1 = 0; i1 < 10; i1++) {
			for (int i = 0 + a1; i < N / 10 + a1; i++) {
				scanf("%f", &a);
				v.push_back(a);
			
			}
			sort(v.begin(), v.end());

			for (int i = 0; i < 7; i++) {
				v2.push_back(v[i]);
			}
			v.clear();
			a1 = a1 + N / 10;

		}


		sort(v2.begin(), v2.end());
	}

	else {
		for (int i = 0; i < N; i++) {
			scanf("%f", &a);
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < 7; i++) {
			v2.push_back(v[i]);
		}
	}


	for (int i = 0; i < 7; i++) {
		float b = v2[i];
		printf("%.3f\n", b);
	}

}


