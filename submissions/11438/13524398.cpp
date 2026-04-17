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

double log2(double x) {
	return log(x) / log(2);
}

void dfs(int x, int depth) {

	for (int i = 0; i < v[x].size(); i++) {
		if (v2[v[x].at(i)].first == 0) {
			v2[v[x].at(i)].first = x;
			v2[v[x].at(i)].second = depth + 1;
			parent[v[x].at(i)][0] = x;
			dfs(v[x].at(i), depth + 1);

		}
	}

}


int LCA(int node1, int node2) {

	if (v2[node1].second < v2[node2].second) {
		int diff = v2[node2].second - v2[node1].second;
		while (diff > 0) {
			int logindex = (int) log2(diff);
			node2 = parent[node2][logindex];
			diff = diff - pow(2, logindex);
		}
	}
	if (v2[node1].second > v2[node2].second) {
		int diff = v2[node1].second - v2[node2].second;
		while (diff > 0) {
			int logindex = (int)log2(diff);
			node1 = parent[node1][logindex];
			diff = diff - pow(2, logindex);
		}
	}

	int tmpindex = 17;

	if (node1 == node2)
		return node1;

	while (1) {
		int f = 0;
		for (int i = tmpindex; i >= 0; i--) {
			if (parent[node1][i] != 0 && parent[node2][i] != 0 && parent[node1][i] != parent[node2][i]) {
				node1 = parent[node1][i];
				node2 = parent[node2][i];
				tmpindex = i;
				f = 1;
				break;
			}
		}
		if (f == 0)
			break;
	}
	if (node1 == node2)
		return node1;
	else
		return parent[node1][0];

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
	//for (int i = 1; i <= N-1; i++) {

	//	v[i].push_back(i+1);
	//	v[i+1].push_back(i);
	//}

	v2[1].first = -1;
	v2[1].second = 0;

	dfs(1, 0);

	for (int index = 2; index <= 100000; index++) {
		for (int j = 1; pow(2, j) <= v2[index].second; j++) {
			parent[index][j] = parent[parent[index][j - 1]][j - 1];
		}
	}

	int M;

	cin >> M;


	for (int i = 0; i < M; i++) {
		scanf("%d %d", &tmp, &tmp1);
		printf("%d\n", LCA(tmp, tmp1));
	}
	//system("Pause");
}