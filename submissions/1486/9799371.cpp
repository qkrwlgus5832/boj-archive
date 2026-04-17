#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <limits.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, T, D;
int graph[26][26];
int dist[700][700];
vector <pair<int, pair<int, int>>> v;


int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

int result = -1;
int count0 = 0;


void floid() {
	for (int k = 0; k < N*M ; k++) {
		for (int i = 0; i < N*M; i++) {
			for (int j = 0; j < N*M ; j++) {
				if (dist[i][k] + dist[k][j] < 0)
					continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}


}

int main() {
	cin >> N >> M >> T >> D;

	char tmp;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp >= 65 && tmp <= 90)
				tmp= tmp - 65;
			else {
				tmp = tmp - 71;
			}
			graph[i][j] = tmp;
			v.push_back(make_pair(tmp, make_pair(i, j)));
		}
	}


	
	sort(v.begin(), v.end());



	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int i1 = 0; i1 < 4; i1++) {
				int nx = i + dir[i1][0];
				int ny = j + dir[i1][1];
				if (nx < 0 || ny < 0 || nx >= M || ny >= N)
					continue;
				int tmp = abs(graph[nx][ny] - graph[i][j]);
				if (tmp <= T && graph[nx][ny] > graph[i][j])
					dist[i*M + j][nx*M + ny] = pow(tmp, 2);
				else if (tmp <= T && graph[nx][ny] <= graph[i][j])
					dist[i*M + j][nx*M + ny] = 1;
				else
					dist[i*M + j][nx*M + ny] = 2000001;

			}

		}
	}
	for (int i = 0; i < N*M ; i++) {
		for (int j = 0; j < N*M ; j++) {
			if (dist[i][j] == 0) {
				if (i == j)
					continue;
				else
				dist[i][j] = 2000001;
			}

		}
	}
	floid();




	for (int i = v.size() - 1; i >= 0; i--) {
		if (dist[0][v[i].second.first * M + v[i].second.second] + dist[v[i].second.first * M + v[i].second.second][0] <= D) {
			cout << v[i].first;
			break;
		}

	
	}
}

