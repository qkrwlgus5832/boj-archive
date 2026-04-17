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

coin getNext(coin& coin_, int dirIndex) {
	coin tmp = coin(coin_.x + dir[dirIndex][0], coin_.y + dir[dirIndex][1]);
	if (tmp.x < 0 || tmp.y < 0 || tmp.x >= N || tmp.y >= M)
		return tmp;
	if (graph[tmp.x][tmp.y] == '#')
		return coin_;
	return tmp;
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
				coin coin1 = getNext(front.firstCoin, i1);
				coin coin2 = getNext(front.secondCoin, i1);


				if (coin1.x < 0 || coin1.y < 0 || coin1.x >=N || coin1.y >= M)
					count++;

				if (coin2.x < 0 || coin2.y < 0 || coin2.x >=N || coin2.y >= M)
					count++;

				if (count == 1) {
					return length;
				}
				else if (count == 2)
					continue;

				if (check[coin1.x][coin1.y][coin2.x][coin2.y] == false) {
					check[coin1.x][coin1.y][coin2.x][coin2.y] = true;
					check[coin2.x][coin2.y][coin1.x][coin1.y] = true;
					q.push(coins(coin1, coin2));
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