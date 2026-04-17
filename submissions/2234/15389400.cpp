#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int n, m;

bool graph[2501][2501];

int dir[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

int check[51][51];

bool check2[51][51][2];

int bfscheck[2501];

class sunggwak {
public:
	int i;
	int j;
	bool flag;
	int count;
	sunggwak(int i, int j, bool flag, int count) {
		this->i = i;
		this->j = j;
		this->flag = flag;
		this->count = count;
	}
};
int getlocation(int i, int j) {
	return i * m + j;
}

void checkwall(int wall, int i, int j) {
	int dd = 1;
	for (int i1 = 0; i1 < 4; i1++) {
		if (wall & dd) {
			
			int ni = i + dir[i1][0];
			int nj = j + dir[i1][1];
			if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
				dd = dd << 1;
				continue;
			}
			graph[getlocation(i, j)][getlocation(ni, nj)] = true;
		}
		dd = dd << 1;
	}
}

int BFS(int i, int j, int answer1) {
	check[i][j] = answer1;
	queue <pair <int, int>> q;
	int count = 1;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		pair <int, int> front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ni = front.first + dir[i][0];
			int nj = front.second + dir[i][1];
			if (ni < 0 || nj < 0 || ni >= n || nj >= m)
				continue;
			if (graph[getlocation(front.first, front.second)][getlocation(ni, nj)] == false && check[ni][nj] == 0) {
				check[ni][nj] = answer1;
				count++;
				q.push(make_pair(ni, nj));
			}
		}
	}
	return count;
}

int BFS2(int i, int j) {
	check2[i][j][0] = true;
	queue <sunggwak> q;
	int maxcount = bfscheck[check[i][j]];
	q.push(sunggwak(i,j,0, 1));

	while (!q.empty()) {
		int s = q.size();
		for (int qsize = 0; qsize < s; qsize++) {
			sunggwak front = q.front();
			q.pop();
			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.i + dir[i1][0];
				int nj = front.j + dir[i1][1];
				if (ni < 0 || nj < 0 || ni >= n || nj >= m)
					continue;
				if (graph[getlocation(front.i, front.j)][getlocation(ni, nj)] == false && check2[ni][nj][front.flag] == false) {
					check2[ni][nj][front.flag] = true;
					q.push(sunggwak(ni, nj, front.flag, front.count+1));
					//maxcount = max(front.count + 1, maxcount);
				}
				else if (front.flag == false && check[ni][nj] != check[i][j]) {
					check2[ni][nj][true] = true;
					maxcount = max(maxcount, bfscheck[check[i][j]] +  bfscheck[check[ni][nj]]);
				}
			}
			
		}
		
	}
	return maxcount;
}


int main() {
	cin >> m >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			checkwall(tmp, i, j);
		}
	}
	int answer1 = 0;
	int answer2 = 0;
	int answer3 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == 0) {
				answer1++;
				int bfsresult = BFS(i, j, answer1);
				answer2= max(answer2, bfsresult);
				bfscheck[answer1] = bfsresult;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		
			answer3 = max(answer3, BFS2(i, j));
			memset(check2, false, sizeof(check2));
			
		}
	}

	cout << answer1 << endl << answer2 << endl << answer3;
	//system("Pause");
}