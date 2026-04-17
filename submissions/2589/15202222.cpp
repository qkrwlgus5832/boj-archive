#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

char graph[51][51];
bool check[51][51];

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };


int N, M;
int BFS(int starti, int startj) {
	queue <pair <int, int>> q;
	bool bfscheck[51][51] = { false, };
	q.push(make_pair(starti, startj));
	bfscheck[starti][startj] = true;

	int count = 0;

	while (!q.empty()) {
		int s = q.size();
		for (int qsize = 0; qsize < s; qsize++) {
			pair <int, int> front = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ni = front.first + dir[i][0];
				int nj = front.second + dir[i][1];
				if (ni < 0 || nj < 0 || ni >= N || nj >= M)
					continue;
				if (bfscheck[ni][nj] == false && graph[ni][nj] == 'L') {
					q.push(make_pair(ni, nj));
					bfscheck[ni][nj] = true;
				}

			}
		}
		count++;
	}
	return count -1 ;
}

int main() {
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 'L' && check[i][j] == false) {
				check[i][j] = true;
				result = max(result,BFS(i, j));
			}
		}
	}
	cout << result;
	//system("Pause");

}