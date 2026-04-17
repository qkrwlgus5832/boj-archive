#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <functional>
#include <math.h>
using namespace std;

set <int> s;

int check[300001];
bool left_right[300001][2];
int root;



int main() {

	int N;
	cin >> N;

	int tmp;
	long long result = 0;



	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);


		if (i == 0) {
			s.insert(tmp);

		}

		else if (i >= 1) {
			//int dd = binary_search(0, i-1, tmp);
			s.insert(tmp);

			set <int>::iterator iter = s.find(tmp);

			
			auto iter2 = iter;
				auto iter3 = iter;
				advance(iter2, 1);
				advance(iter3, -1);
				if (iter2 == s.end()) {
					check[tmp] = check[*iter3] + 1;
					left_right[*iter3][1] = true;
				}
				else if (iter3 == s.end()) {
					check[tmp] = check[*iter2] + 1;
					left_right[*iter2][0] = true;
				}
				else {
					check[tmp] = max(check[*iter2], check[*iter3]) + 1;

				}



			result += check[tmp];



		}

		printf("%lld\n", result);


	}

	


}