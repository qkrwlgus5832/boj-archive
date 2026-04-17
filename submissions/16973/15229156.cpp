#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;



bool graph[1001][1001];

vector <pair <int, int>> wall;

int dir[4][2] = { {-1,0 },{1,0},{0, -1}, {0,1} };
int h, w;

bool checkIfInWall(int starti, int startj) {
	
	for (int i = 0; i < wall.size(); i++) {
		if (starti <= wall[i].first  && wall[i].first  < starti + h) {
			if (startj <= wall[i].second &&  wall[i].second < startj + w)
				return true;
		}
	}
	return false;
}

int BFS(int sr, int sc, int fr, int fc) {
	queue <pair <int, int>> q;
	bool check[1001][1001] = { false, };
	q.push(make_pair(sr, sc));
	check[sr][sc] = true;

	int count = 0;

	while (!q.empty()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			pair <int, int> front = q.front();
			q.pop();
			if (front.first == fr && front.second == fc)
				return count;
			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.first + dir[i1][0];
				int nj = front.second + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= N || nj >= M)
					continue;
				if (check[ni][nj] == false && checkIfInWall(ni, nj) == false) {
					check[ni][nj] = true;
					q.push(make_pair(ni, nj));
				}
			}
		}
		count++;
	}
	return -1;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				wall.push_back(make_pair(i, j));
			}
		}
	}
	
	int sr, sc, fr, fc;
	cin >> h >> w >> sr >> sc >> fr >> fc;

	cout << BFS(sr- 1,sc- 1, fr-1, fc- 1);
	//system("Pause");
}