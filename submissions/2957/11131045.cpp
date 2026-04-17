#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <functional>
#include <math.h>
using namespace std;

vector <int> s;

int check[300001];

int root;

int binary_search(int x, int y, int x1) {
	if (x + 1 == y) {
		if (abs(x1 - s[x]) < abs(x1 - s[y]))
			return x;
		else
			return y;
	}
	else if (x == y) {
			return x;
	}
	else if (s[(x + y) / 2] < x1 ) {
			return binary_search((x + y) / 2 , y, x1);

	}

	else if (s[(x + y) / 2] > x1) {
			return binary_search(x, (x + y) / 2, x1);
	}
	




}

int main() {

	int N;
	cin >> N;

	s.resize(300001);
	int tmp;
	long long result = 0;


	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
	
		if (i == 0) {
			s.insert(s.begin(), tmp);
		
		}

		else if (i >= 1) {
			int dd = binary_search(0, i-1, tmp);

			auto iter = s.begin();

			if (s[dd] > tmp) {
				iter = iter + dd;
				if (dd - 1 >= 0)
					check[tmp] = max(check[s[dd]], check[s[dd - 1]]) + 1;
				else
					check[tmp] = check[s[dd]] + 1;
				s.insert(iter, tmp);

			}
			else {
				iter = iter + dd+1;
				check[tmp] = max(check[s[dd]], check[s[dd + 1]]) + 1;
		

				s.insert(iter, tmp);
			}
		
			result += check[tmp];
		
			
			
		}
		
		printf("%lld\n", result);
	

	}




}