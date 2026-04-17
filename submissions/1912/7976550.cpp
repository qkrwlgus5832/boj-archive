#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


int N1[100001];

int n;
vector <int> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &N1[i]);

	int sum = 0;

	int f = 0;
	int min = N1[0];
	for (int i = 0; i < n; i++) {
		if (N1[i] >= 0)
			f = 1;
		if (min < N1[i])
			min = N1[i];

	}
	if (f == 0)
		cout << min;
	else {


		for (int i = 0; i < n; i++) {
			if (N1[i] < 0) {

				v.push_back(sum);
				sum = 0;


			}
			else if (i == n - 1) {
				sum = sum + N1[i];
				v.push_back(sum);
			}

			else {
				sum = sum + N1[i];
			}

		}
		sort(v.begin(), v.end());


		cout << v[v.size() - 1];
	}

}