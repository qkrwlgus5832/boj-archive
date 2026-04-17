#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int map[11][11];
int unionfind[7];

struct node {
	int distance;
	int depart;
	int arrive;

	node(int distance, int depart, int arrive) : distance(distance), depart(depart), arrive(arrive) {}
};
struct compare {
	bool operator()(node &a, node &b) {
		return a.distance > b.distance;
	}
};
priority_queue <node, vector <node>, compare> bridgeminq;
int N, M;

int dir[4][2] = { {1, 0}, {0, 1}, {-1,0}, {0, -1} };

int check[11][11];
bool cango[11][11];

set<int> bridge;

void islandBFS(int i, int j, int number) {
	queue <pair <int, int>> q;
	check[i][j] = number;
	q.push({ i,j });

	while (q.size()) {
		pair <int, int> front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ni = front.first + dir[i][0];
			int nj = front.second + dir[i][1];
			if (ni < 0 || nj < 0 || ni >= N || nj >= M)
				continue;
			if (check[ni][nj] == false && map[ni][nj] == 1) {
				q.push({ ni,nj });
				check[ni][nj] = number;
			}
		}

	}

}

pair <int, pair <int, int>> BFS(pair <int, int> start, char direction) {
	if (direction == 'r') {
		direction = 1;
	}
	else if (direction == 'd') {
		direction = 0;
	}
	int distance = 1;
	int depart = check[start.first + dir[direction][0] * -1][start.second + dir[direction][1] * -1];
	if (depart == 0) {
		return { 1, {0,0} };
	}
	queue <pair <int,int>> q;
	q.push(start);

	while (q.size()) {
		pair <int, int> front = q.front();
		q.pop();
		int ni = front.first + dir[direction][0];
		int nj = front.second + dir[direction][1];

		if (ni < 0 || nj < 0 || ni >= N || nj >= M) {
			continue;
		}
		
		if (map[ni][nj] == 0) {
			q.push({ ni,nj });
		}
		else {
			return { distance , { depart, check[ni][nj] } };
		}
		distance++;
	}
	return { 1, {0,0} };
}

void connectIsland(int i, int j) {
	pair <int, pair <int, int>> result;
	if (i > 0 && i < N-1 ) {
		result = BFS({ i,j }, 'd');
		if (result.first > 1) {
			bridgeminq.push(node(result.first, result.second.first, result.second.second));
		}
	}
	if (j > 0 && j < M - 1) {
		result = BFS({ i,j }, 'r');
		if (result.first > 1) {
			bridgeminq.push(node(result.first, result.second.first, result.second.second));
		}
	}

}
int find_(int island) {
	if (unionfind[island] == 0) {
		return island;
	}
	return find_(unionfind[island]);
}

void union_(int island1, int island2) {
	int parentisland1 = find_(island1);
	int parentisland2 = find_(island2);

	if (parentisland1 < parentisland2) {
		unionfind[parentisland2] = parentisland1;
	}
	else {
		unionfind[parentisland1] = parentisland2;
	}
}

bool isAnswer(int totalIslandCount) {
	int parentCompare = find_(1);
	for (int i = 2; i <= totalIslandCount; i++) {
		if (parentCompare != find_(i))
			return false;
	}
	return true;
}
int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int number = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				if (check[i][j] == false)
					islandBFS(i, j, number++);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				connectIsland(i, j);
			}
		}
	}
	int result = 0;
	int count = 0;
	bool flag = false;
	while (bridgeminq.size()) {
		if (isAnswer(number - 1)) {
			flag = true;
			break;
		}
		int depart = bridgeminq.top().depart;
		int arrive = bridgeminq.top().arrive;
		int distance = bridgeminq.top().distance;

		bridgeminq.pop();

		int parentDepart = find_(depart);
		int parentArrvie = find_(arrive);

		if (parentDepart == parentArrvie) {
			continue;
		}
		else {
			union_(depart, arrive);
			result += distance;
		}

	}
	if (flag == true) {
		cout << result;
	}
	else if (isAnswer(number-1)){
		cout << result;
	}
	else {
		cout << -1;
	}


	//system("Pause");
}