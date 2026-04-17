#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector <pair <int, int>> v[101][101];

int dir[4][2] = { {-1,0}, {1,0},{0, -1}, {0, 1} };

bool check[101][101];
bool visitcheck[101][101];

int N, M;
int result = 0;

bool cango(pair <int, int> start, pair <int, int> dest) {
	bool bfscheck[101][101] = { false, };
	queue < pair <int, int>> q;
	q.push(start);
	while (!q.empty()) {
		pair <int, int> front = q.front();
		q.pop();
		if (front.first == dest.first && front.second == dest.second)
			return true;
		for (int i1 = 0; i1 < 4; i1++) {
			int ni = front.first + dir[i1][0];
			int nj = front.second + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= N)
				continue;

			if (check[ni][nj] == true && bfscheck[ni][nj] == false) {
				bfscheck[ni][nj] = true;
				q.push(make_pair(ni, nj));
			}

		}
	}
	return false;

}
int recursion(int i, int j) {
	int tmp = 0;
	int count = 0;
	for (int i1 = 0; i1 < v[i][j].size(); i1++) {
		int roomi = v[i][j][i1].first;
		int roomj = v[i][j][i1].second;
		if (check[roomi][roomj] == false) {
			check[roomi][roomj] = true;
			count++;
		}
	}
	
	for (int i1 = 0; i1 < v[i][j].size(); i1++) {
		int ni = v[i][j][i1].first;
		int nj = v[i][j][i1].second;
		if (check[ni][nj] == true && cango(make_pair(i, j), make_pair(ni, nj))) {
			tmp = max(tmp, recursion(ni, nj));
		}
	}
	
	if (tmp == 0)
		return count;
	return tmp + count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N >> M;
	
	int a, b, c, d;

	for (int i = 0; i < M; i++) {
		
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		
		v[a][b].push_back(make_pair(c, d));
	}
	check[0][0] = true;
	cout << recursion(0, 0) + 1;
	
	//system("Pause");

}