#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector <pair <int, int>> v[101][101];

int dir[4][2] = { {-1,0}, {1,0},{0, -1}, {0, 1} };


int N, M;
int result = 0;
bool check[101][101];

bool cango(pair <int, int> location) {
	for (int i = 0; i < 4; i++) {
		int ni = location.first + dir[i][0];
		int nj = location.second + dir[i][1];
		if (ni < 0 || nj < 0 || ni >= N || nj >= N)
			continue;
		if (check[ni][nj] == true)
			return true;
	}
	return false;
}

bool DFS(int i, int j) {
		int count = 0;
		int tmp = 0;
		bool flag = false;
		for (int i1 = 0; i1 < v[i][j].size(); i1++) {
			int ni = v[i][j][i1].first;
			int nj = v[i][j][i1].second;
			if (check[ni][nj] == false) {
				result++;
				flag = true;
				check[ni][nj] = true;
			}
		}
		for (int i1 = 0; i1 < v[i][j].size(); i1++) {
			int ni = v[i][j][i1].first;
			int nj = v[i][j][i1].second;

			if (cango({ ni,nj })) {
				bool flag2 = DFS(ni, nj);
				flag = (flag || flag2);
			}
		}

		return flag;
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
	while (1) {
		bool flag = DFS(0, 0);
		if (flag == false)
			break;
	}
	cout << result + 1;

	//system("Pause");

}