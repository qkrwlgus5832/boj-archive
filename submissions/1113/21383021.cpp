#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;

int graph[51][51];
int answer[51][51];
bool check[51][51];

int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

void checkCommitted(vector <pair <int ,int>> &tmp) {
	for (int i = 0; i < tmp.size(); i++) {
		check[tmp[i].first][tmp[i].second] = true;
		answer[tmp[i].first][tmp[i].second]--;
	}
}

bool bfs(queue <pair <int,int>> &q, bool bfscheck[51][51]) {
	vector <pair <int, int>> tmp;
	
	while (q.size()) {
		pair <int, int> front = q.front();
		q.pop();
		tmp.push_back(front);

		for (int i1 = 0; i1 < 4; i1++) {
			int ni = front.first + dir[i1][0];
			int nj = front.second + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M) {
				checkCommitted(tmp);
				return false;
			}

			if (bfscheck[ni][nj] == false && answer[ni][nj] > 0) {
				bfscheck[ni][nj] = true;
				q.push({ ni,nj });
			}
		}
	}
	return true;
}

int getAnswer() {
	int result = 0;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			result += answer[i][j];
		}
	}
	return result;
}
int main() {
	cin >> N >> M;
	int maxHeight = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &graph[i][j]);
			maxHeight = max(maxHeight, graph[i][j]);
		}

	}
	int result = 0;

	for (int h=2; h<= maxHeight + 1; h++){
		queue <pair <int, int>> q;
		bool bfscheck[51][51] = { false, };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] < h && check[i][j] == false) {
					answer[i][j]++;
					if (i!=0 && j!=0 && i!= N-1 && j!= M-1) {
						if (bfscheck[i][j] == false) {
							bfscheck[i][j] = true;
							q.push({ i,j });
			
						}
					}
				}
			}
		}
		bfs(q, bfscheck);
	}


	cout << getAnswer();
	//system("Pause");
}
