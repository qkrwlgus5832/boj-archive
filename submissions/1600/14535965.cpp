#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int K;

int graph[201][201];
bool check[201][201][31];


int dir[4][2] = { {-1,0} ,{1,0}, {0,-1}, {0,1} };
int knightdir[8][2] = { {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {2,1}, {1,2}, {2, -1}, {1, -2} };

int W, H;
class monkey {
public:
	int i;
	int j;
	int horsek;
	int count;
	monkey(int i, int j, int horsek, int count) {
		this->i = i;
		this->j = j;
		this->horsek = horsek;
		this->count = count;
	}
};
queue <monkey> q;

int BFS(int i, int j) {
	q.push(monkey(i, j, K, 0));
	check[i][j][K] = true;

	int level = 0;
	while (!q.empty()) {
		int s = q.size();
		
		monkey tmpmonkey = q.front();
		q.pop();
		if (tmpmonkey.i == H - 1 && tmpmonkey.j == W - 1)
			return tmpmonkey.count;

		for (int i1 = 0; i1 < 4; i1++) {
			int ni = tmpmonkey.i + dir[i1][0];
			int nj = tmpmonkey.j + dir[i1][1];

			if (ni < 0 || nj < 0 || ni >= H || nj >= W)
					continue;

			if (graph[ni][nj] == 0 && check[ni][nj][tmpmonkey.horsek] == false) {
				q.push(monkey(ni, nj, tmpmonkey.horsek, tmpmonkey.count+1));
				check[ni][nj][tmpmonkey.horsek] = true;
			}
		}
			
		if (tmpmonkey.horsek >= 1) {
			for (int i1 = 0; i1 < 8; i1++) {
			
				int ni = tmpmonkey.i + knightdir[i1][0];
				int nj = tmpmonkey.j + knightdir[i1][1];

				if (ni < 0 || nj < 0 || ni >= H || nj >= W)
					continue;
				if (graph[ni][nj] == 0 && check[ni][nj][tmpmonkey.horsek - 1] == false) {
					q.push(monkey(ni, nj, tmpmonkey.horsek - 1, tmpmonkey.count + 1));
					check[ni][nj][tmpmonkey.horsek - 1] = true;
				}

	
			}
		}
	}
	return -1;
}


int main() {
	cin >> K;
	
	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> graph[i][j];
		}
	}

	cout << BFS(0, 0);
	//system("Pause");
}

