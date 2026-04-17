#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int K;

int graph[201][201];
bool check[201][201][31];


int dir[4][2] = { {-1,0} ,{1,0}, {0,-1}, {0,1} };

int W, H;
class monkey {
public:
	int i;
	int j;
	int horsek;
	monkey(int i, int j, int horsek) {
		this->i = i;
		this->j = j;
		this->horsek = horsek;
	}
};
queue <monkey> q;

int BFS(int i, int j) {
	q.push(monkey(i, j, K));
	check[i][j][K] = true;
	int level = 0;
	while (!q.empty()) {
		int s = q.size();
		for (int count = 0; count < s; count++) {
			monkey monkey_ = q.front();
			q.pop();
			if (monkey_.i == H - 1 && monkey_.j == W - 1)
				return level;

			for (int i1 = 0; i1 < 4; i1++) {
				int ni = monkey_.i + dir[i1][0];
				int nj = monkey_.j + dir[i1][1];

				if (ni < 0 || nj < 0 || ni >= H || nj >= W)
					continue;

				if (graph[ni][nj] == 0 && check[ni][nj][monkey_.horsek] == false) {
					q.push(monkey(ni, nj, monkey_.horsek));
					check[ni][nj][monkey_.horsek] = true;
				}
			}
			
			if (monkey_.horsek >= 1) {
				for (int j = -2; j <= 2; j++) {
					if (j == 0)
						continue;
					int ni = monkey_.i + (2 / abs(j));
					int nj = monkey_.j + j;

					if (ni < 0 || nj < 0 || ni >= H || nj >= W)
						continue;
					if (graph[ni][nj] == 0 && check[ni][nj][monkey_.horsek - 1] == false) {
						q.push(monkey(ni, nj, monkey_.horsek - 1));
						check[ni][nj][monkey_.horsek - 1] = true;
					}

					 ni = monkey_.i - (2 / abs(j));
					 nj = monkey_.j + j;

					 if (ni < 0 || nj < 0 || ni >= H || nj >= W)
						 continue;

					 if (graph[ni][nj] == 0 && check[ni][nj][monkey_.horsek - 1] == false) {
						 q.push(monkey(ni, nj, monkey_.horsek - 1));
						 check[ni][nj][monkey_.horsek - 1] = true;
					 }

				}
			}

		}
		level++;
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

