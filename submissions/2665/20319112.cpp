#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int graph[51][51];

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int n;

class node {
public:
	int x;
	int y;
	bool check[51][51] = { false, };
};

bool BFS(node blackChecks) {		

	bool bfscheck[51][51] = { false, };
	queue <pair <int, int>> q;
	q.push({ 0,0 });

	bfscheck[0][0] = true;
	
	while (q.size()) {
		pair <int, int> front = q.front();
		q.pop();

		if (front.first == n - 1 && front.second == n - 1)
			return true;

		for (int i1 = 0; i1 < 4; i1++) {
			int ni = front.first + dir[i1][0];
			int nj = front.second + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= n || nj >= n)
				continue;
			if (graph[ni][nj] == 1 || blackChecks.check[ni][nj] == true)
				if (bfscheck[ni][nj] == false) {
					bfscheck[ni][nj] = true;
					q.push({ ni,nj });
				}

		}

	}
	return false;

}

int recursion(vector <pair <int, int>> black, vector <int> v) {
	queue <node> q;
	int depth = 0;

	q.push(node());

	while (1) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			node front = q.front();
			q.pop();

			if (BFS(front))
				return depth;
			for (int i = 0; i < black.size(); i++) {
				if (front.check[black[i].first][black[i].second] == false) {
					node tmp = front;
					tmp.check[black[i].first][black[i].second] = true;
					q.push(tmp);
				}

			}
		}
		depth++;
	}
}
int main() {

	cin >> n;
	vector <pair <int, int>> black;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &graph[i][j]);
			if (graph[i][j] == 0) {
				black.push_back({ i,j });
			}
		}
	}
	

	cout << recursion(black, vector <int> ());
	//system("Pause");
}
