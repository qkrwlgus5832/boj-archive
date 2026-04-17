#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector <vector <int>> v;

vector <pair <int, int >> v2;


int parent[100001][18];

int N;

void dfs(int x, int depth) {

	for (int i = 0; i < v[x].size(); i++) {
		if (v2[v[x].at(i)].first == 0) {
			v2[v[x].at(i)].first = x;
			v2[v[x].at(i)].second = depth + 1;
			parent[v[x].at(i)][0] = x;
			for (int j = 1; pow(2, j) <= depth + 1; j++) {
				parent[v[x].at(i)][j] = parent[parent[v[x].at(i)][j - 1]][j - 1];
			}
			dfs(v[x].at(i), depth + 1);

		}
	}
}


int LCA(int node1, int node2) {

	if (v2[node1].second < v2[node2].second) {
		int gap = v2[node2].second - v2[node1].second;
		while (1) {
			int dd = 1;
			int count = 0;
			while (1) {
				if (dd * 2 > gap) {
					gap = gap - pow(2, count);
					node2 = parent[node2][count];
					break;
				}
				dd = dd * 2;
				count++;
			
			}
			if (gap == 0)
				break;
		}


	
	}
	else if (v2[node1].second > v2[node2].second) {
		int gap = v2[node1].second - v2[node2].second;
		while (1) {
			int dd = 1;
			int count = 0;
			while (1) {

				if (dd * 2 > gap) {
					gap = gap - pow(2, count);
					node1 = parent[node1][count];
					break;
				}
				dd = dd * 2;
				count++;

			}
			if (gap == 0)
				break;
		}
	}
	



	while (1) {
		if (node1 == node2)
			return node2;
		for (int i = 0; i <= 17; i++) {
			if (parent[node1][i] != 0 && parent[node2][i] != 0 && parent[node1][i] == parent[node2][i]) {
				if (i >= 1) {
					node1 = parent[node1][i - 1];
					node2 = parent[node2][i - 1];
				}
				else {
					node1 = parent[node1][i];
					node2 = parent[node2][i];
				}
				break;
			}
		}
		
	}

}




int main() {
	cin >> N;
	int tmp, tmp1;
	v.resize(100001);
	v2.resize(100001);
	for (int i = 0; i < N - 1; i++) {

		scanf("%d %d", &tmp, &tmp1);
		v[tmp].push_back(tmp1);
		v[tmp1].push_back(tmp);
	}


	v2[1].first = -1;
	v2[1].second = 0;

	dfs(1, 0);





	int M;



	cin >> M;


	for (int i = 0; i < M; i++) {
		scanf("%d %d", &tmp, &tmp1);
		printf("%d\n", LCA(tmp, tmp1));
	}

	
}