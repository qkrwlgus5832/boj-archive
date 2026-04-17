#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

char graph[51][51];

int nodeCount = 0;
bool check[51][51];

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N, M;

int BFS(int i, int j) {
	bool bfscheck[51][51] = { false, };
	bfscheck[i][j] = true;

	queue <pair <int, int>> q;
	q.push({ i,j });

	int length = 0;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			pair <int, int> front = q.front();
			q.pop();

			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.first + dir[i1][0];
				int nj = front.second + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= N || nj >= N)
					continue;

				if (bfscheck[ni][nj] == false && graph[ni][nj] != '1') {
					if (graph[ni][nj] == '0' || graph[ni][nj] == '1') {
						bfscheck[ni][nj] = true;
						q.push({ ni,nj });
					}
					else {
						if (check[ni][nj] == true)
							nodeCount++;
						else {
							check[ni][nj] = true;
							nodeCount += 2;
						}
						return length + 1;
					}
				}
			}
		}
		length++;
	}

}
int main() {

	cin >> N >> M;



	pair <int, int> start;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'S') {
				start = { i,j };
			}
		}
		
	}
	
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((graph[i][j] == 'S' || graph[i][j] == 'K') && check[i][j]== false) {
				check[i][j] = true;
				result += BFS(i, j);
			}
		}
	}
	if (nodeCount-1 == M)
		cout << result;
	else
		cout << -1;
	//system("Pause");
}
