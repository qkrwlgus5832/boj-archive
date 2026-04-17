#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;

bool check[22][22][22][22];
char graph[22][22];
int result = INT_MAX;

class coin {
public:
	int x;
	int y;
	int time;
	coin() {};
	coin(int x, int y, int time) {
		this->x = x;
		this->y = y;
		this->time = time;
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

coin& getNext(coin coin_, int dirIndex) {
	coin tmp = coin(coin_.x + dir[dirIndex][0], coin_.y + dir[dirIndex][1], coin_.time + 1);
	if (tmp.x < 0 || tmp.y < 0 || tmp.x >= N || tmp.y >= M)
		return tmp;
	if (graph[tmp.x][tmp.y] == '#') {
		coin_.time++;
		return coin_;
	}
	return tmp;
}

int checkIfAnswer(const vector <coin> &v) {
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].x < 0 || v[i].y < 0 || v[i].x >= N || v[i].y >= M)
			count++;
	}
	return count;
}
int BFS(coin first, coin second) {
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
				first = getNext(front.firstCoin, i1);
				second = getNext(front.secondCoin, i1);

				if (first.time >= 10 || second.time >= 10)
					continue;
				if (checkIfAnswer({ first, second }) == 1) {
					result = min(result, first.time);
					continue;
				}
				else if (checkIfAnswer({ first, second }) == 2)
					continue;

				if (check[first.x][first.y][second.x][second.y])
					continue;
				
				check[first.x][first.y][second.x][second.y] = true;
				check[second.x][second.y][first.x][first.y] = true;
				q.push(coins(first, second));
			}
		}
	
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
				v.push_back(coin(i, j, 0));
			}
		}
	}

	BFS(v[0], v[1]);
	if (result == INT_MAX)
		cout << -1;
	else
		cout << result;
	//system("Pause");
}
