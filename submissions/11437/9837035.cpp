#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector <vector <int>> v;

vector <pair <int, int >> v2;




int N;

void dfs(int x, int depth) {
	
	for (int i = 0; i < v[x].size(); i++) {
		if (v2[v[x].at(i)].first == 0) {
			v2[v[x].at(i)].first = x;
			v2[v[x].at(i)].second = depth + 1;

			dfs(v[x].at(i), depth + 1);

		}


	}


}
int LCA(int node1, int node2) {
	if (v2[node1].second < v2[node2].second) {
		int gap = v2[node2].second - v2[node1].second;
		for (int i = 0; i < gap; i++) {
			node2 = v2[node2].first;
		}
	}
	else if (v2[node1].second > v2[node2].second) {
		int gap = v2[node1].second - v2[node2].second;
		for (int i = 0; i < gap; i++) {
			node1 = v2[node1].first;
		}
	}


	while (1) {
		if (node2 == node1)
			return node2;
		else {
			node2 = v2[node2].first;
			node1 = v2[node1].first;
		}
	}

}




int main() {
	cin >> N;
	int tmp, tmp1; 
	v.resize(50001);
	v2.resize(50001);
	for (int i = 0; i < N-1; i++) {

		scanf("%d %d", &tmp, &tmp1);
		v[tmp].push_back(tmp1);
		v[tmp1].push_back(tmp);
	}


	v2[1].first = -1;
	v2[1].second = 1;

	dfs(1, 1);





	int M;



	cin >> M;


	for (int i = 0; i < M; i++) {
		scanf("%d %d", &tmp, &tmp1);
		printf("%d\n", LCA(tmp, tmp1));
	}


}