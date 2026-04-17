#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector <pair <int, int>> v;
bool check[100001];
int N;
int tmp1, tmp2;


bool compare(pair <int, int> a, pair <int, int> b) {
	return a.first > b.first;
}



int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &tmp1, &tmp2);
		v.push_back(make_pair(tmp1, tmp2));

	}
	sort(v.begin(), v.end(), compare);






	int tmp = 0;
	int count = 0;
	while (1) {
		int dd = -1;
		int tmpi;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].first >= tmp) {
				if (check[i] == false) {
					if (dd == -1) {
						dd = v[i].second;
						check[i] = true;
						tmpi = i;
					}




					else if (v[i].second < dd) {
						dd = min(v[i].second, dd);
						check[tmpi] = false;
						check[i] = true;
						tmpi = i;
					}


				}
			}

			else
				break;
		}
			if (dd != -1)
				count++;
			else {
				break;
			}
			tmp = dd;

		}
	


	cout << count;
}
