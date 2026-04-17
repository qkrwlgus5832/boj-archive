#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;


int K;
int V, E;
int node1, node2;
vector <vector <int>>  v;
int check[20001];
int bfs(int x) {
	queue <int> q;
	
	q.push(x);
	check[x] = 1;

	while (!q.empty()) {
		int a = q.size();
		for (int j = 0; j < a; j++) {
			x = q.front();
			q.pop();
			for (int i = 0; i < v[x].size(); i++) {
				if (check[v[x].at(i)] == -1) {
					check[v[x].at(i)] = !check[x];
					q.push(v[x].at(i));
				}
				else {
					if (check[v[x].at(i)] == check[x])
						return 0;

				}

			}
		}

	}
	return 1;
}

int main() {
	cin >> K;



	for (int i = 0; i < K; i++) {
		v.resize(20001);
		memset(check, -1, sizeof(check));
		scanf("%d %d", &V, &E);
		for (int i1 = 0; i1 < E; i1++) {
			scanf("%d %d", &node1, &node2);
			v[node1].push_back(node2);
			v[node2].push_back(node1);


		}

		int result = bfs(1);
		if (result == 1) {
			printf("YES\n");
			
		}
		else if (result == 0) {
			printf("NO\n");
		}
		v.clear();

	}

}