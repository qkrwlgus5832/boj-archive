#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
using namespace std;

int dd[201][201];
vector< pair <int, int>> v;
int t;
int n;



void beer() {
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			int mx = max(v[i].first, v[j].first);
			int nx = min(v[i].first, v[j].first);
			int my = max(v[i].second, v[j].second);
			int ny = min(v[i].second, v[j].second);
			if (mx - nx + my - ny <= 1000) {
				dd[i][j] = 1;
				dd[j][i] = 1;
			}

		}

	}

}
void floid() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dd[i][j] = max(dd[i][j], dd[i][k] + dd[k][j]);
			}
		}
	}

}

int main() {
	cin >> t;
	int tt1, tt2;
	
	for (int i = 0; i < t; i++) {
		int result = 0;
		memset(dd, 0, sizeof(dd));
		pair <int, int> home;
		pair <int, int> songdo;
		scanf("%d", &n);
		scanf("%d %d", &home.first, &home.second);
		v.push_back(make_pair(home.first, home.second));
		for (int i1 = 0; i1 < n; i1++) {
			scanf("%d %d", &tt1, &tt2);
			v.push_back(make_pair(tt1, tt2));
		}
		scanf("%d %d", &songdo.first, &songdo.second);
		
		v.push_back(make_pair(songdo.first, songdo.second));


		beer();
		floid();
		if (dd[0][v.size() - 1] >= 1)
			printf("happy\n");
		else
			printf("sad\n");
		
		v.clear();


	}

}