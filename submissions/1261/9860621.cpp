#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <functional>
using namespace std;

int N, M;
int graph[101][101];
int dirx[4] = { 0,0,-1,1 };
int diry[4] = { -1,1,0,0 };
bool check[101][101];
int result = -1;


int dikjstra(int i) {
	priority_queue <pair<int, int>, vector <pair< int, int>>, greater <pair<int, int>>> q;
	int G[10001];
	memset(G, 1, sizeof(G));
	G[i] = 0;
	q.push(make_pair(0, i));

	while (!q.empty()) {
		int dis = q.top().first;
		int v1 = q.top().second;
		q.pop();
		int i = v1 / M;
		int j = v1 % M;

		check[i][j] = true;

				for (int i2 = 0; i2 < 4; i2++) {
					int ni2 = i + dirx[i2];
					int nj2 = j + diry[i2];
					if (ni2 < 0 || nj2 < 0 || ni2 >= N || nj2 >= M)
						continue;
					if (check[ni2][nj2] == false) {
						if (G[ni2*M + nj2] > dis + graph[ni2][nj2]) {
							G[ni2*M + nj2] = dis + graph[ni2][nj2];
							q.push(make_pair(dis + graph[ni2][nj2], ni2 * M + nj2));

						}
					}

				}


			}

	
	return G[(N - 1) * M + M - 1];

}


int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &graph[i][j]);

		}
	}





	
	cout << dikjstra(0);


}