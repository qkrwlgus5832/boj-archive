#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

int N;
int arr[126][126];
vector <vector<pair<int, int>> > graph;
int dikjstra(int i) {
	priority_queue <pair<int, int>, vector <pair< int, int>>, greater <pair<int, int>>> q;
	bool check[16000] = { false, };
	int G[16000];
	memset(G, 1, sizeof(G));
	check[i] = true;
	G[i] = arr[0][0];
	q.push(make_pair(arr[0][0], i));

	while (!q.empty()) {
		int dis = q.top().first;
		int v1 = q.top().second;
		q.pop();
		check[v1] = true;
		for (int i1 = 0; i1 < graph[v1].size(); i1++) {
			if (check[graph[v1][i1].first] == false) {
				if (G[graph[v1][i1].first] > dis + graph[v1][i1].second) {
					G[graph[v1][i1].first] = dis + graph[v1][i1].second;
					q.push(make_pair(dis + graph[v1][i1].second, graph[v1][i1].first));

				}


			}

		}
	}

	return G[( N-1) * N + N-1];

}




int main() {
	int count = 0;




	while (1) {
		count++;
		graph.resize(126 * 126);
		scanf("%d", &N);
		if (N == 0)
			break;
	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = 0;
				scanf("%d", &arr[i][j]);
			}
		}
		int dirx[4] = { 0,0,-1,1 };
		int diry[4] = { -1,1,0,0 };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int i1 = 0; i1 < 4; i1++) {
					int nx = i + dirx[i1];
					int ny = j + diry[i1];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
						continue;
					else
						graph[i*N + j].push_back(make_pair(nx*N + ny, arr[nx][ny]));

				}



			}
		}


		printf("Problem %d: %d\n", count , dikjstra(0));
		graph.clear();
	}


}