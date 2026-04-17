#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;

bool check[21][21][21][21];
char graph[21][21];

class coin {
public:
	int x;
	int y;
	coin() {};
	coin(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class coins {
public:
	coin firstCoin;
	coin secondCoin;

	coins(coin firstCoin, coin secondCoin) {
		this->firstCoin = firstCoin;
		this->secondCoin = secondCoin;
	}
};

int dir[4][2] = { {-1, 0}, { 1,0 }, { 0,-1 }, { 0,1 } };

bool checkIn(int &i, int &j, int &ni, int &nj) {
	if (ni < 0 || nj < 0 || ni >= N || nj >= M)
		return false;
	if (graph[ni][nj] == '#') {
		ni = i; nj = j;
	}
	return true;
}
int BFS(coin &first, coin &second) {
	queue <coins> q;

	q.push(coins(first, second));

	check[first.x][first.y][second.x][second.y] = true;
	check[second.x][second.y][first.x][first.y] = true;

	int length = 1;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			coins front = q.front();
			q.pop();

			for (int i1 = 0; i1 < 4; i1++) {
				int count = 0;
				int ni = front.firstCoin.x + dir[i1][0];
				int nj = front.firstCoin.y + dir[i1][1];


				if (checkIn(front.firstCoin.x, front.firstCoin.y, ni, nj) == false)
					count++;
				
				int ni2 = front.secondCoin.x + dir[i1][0];
				int nj2 = front.secondCoin.y + dir[i1][1];

				if (checkIn(front.secondCoin.x, front.secondCoin.y, ni2, nj2) == false)
					count++;

				if (count == 1) {
					return length;
				}
				else if (count == 2)
					continue;

				if (ni >= 0 && nj >=0 && ni2 < N && nj2 < M && check[ni][nj][ni2][nj2] == false) {
					check[ni][nj][ni2][nj2] = true;
					check[ni2][nj2][ni][nj] = true;
					q.push(coins(coin(ni, nj), coin(ni2, nj2)));
				}
			}
		}
		length++;
		if (length == 11)
			return -1;
	}
	return -1;
}
int main() {
	cin >> N >> M;

	vector <coin> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'o') {
				v.push_back(coin(i, j));
			}
		}
	}

	cout << BFS(v[0], v[1]);
	//system("Pause");
}