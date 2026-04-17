#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

vector <pair <int, int >> v;
int main() {

	cin >> N;
	int am, ad, bm, bd;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &am, &ad, &bm, &bd);
		v.push_back(make_pair(am * 100 + ad, bm * 100 + bd));

	}
	sort(v.begin(), v.end());

	int tmp = 301;
	int f = 0;
	int count = 0;



	int dd;
	while (1) {
		if (tmp > 1130) {
			cout << count;
			break;
		}


		for (int i = 0; i < v.size(); i++) {
			if (v[i].first <= tmp) {
				f = 1;
				dd = v[i].second;
	
			}
			else {
				break;
			}

		}
		if (f==1)
		count++;
		else {
			cout << 0;
			break;
		}
		tmp = dd;
	}



}