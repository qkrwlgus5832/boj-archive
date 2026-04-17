#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <memory.h>

using namespace std;

char graph[51][51];
char tmpgraph[51][51];

vector <pair <int,int>> mirror;
int result = INT_MAX;

int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
vector <pair <int, int>> doors;

int N;

class node {
public:
	int x;
	int y;
	int direction;

	node(int x, int y, int direction) {
		this->x = x;
		this->y = y;
		this->direction = direction;
	}
};

pair <int, int> changeDirection(int dir) {
	if (dir == 0)
		return { 2,3 };
	else if (dir == 1)
		return { 2,3 };
	else if (dir == 2)
		return { 0,1 };

	return { 0,1 };
}

bool checkIfAnswer() {
	queue <node> q;
	bool bfscheck[51][51] = { false, };

	q.push(node(doors[0].first, doors[0].second, 0));
	q.push(node(doors[0].first, doors[0].second, 1));
	q.push(node(doors[0].first, doors[0].second, 2));
	q.push(node(doors[0].first, doors[0].second, 3));

	bfscheck[doors[0].first][doors[0].second] = true;

	while (q.size()) {
		node front = q.front();
		q.pop();

		if (front.x == doors[1].first && front.y == doors[1].second)
			return true;

		int ni = front.x + dir[front.direction][0];
		int nj = front.y + dir[front.direction][1];

		if (ni < 0 || nj < 0 || ni >= N || nj >= N || graph[ni][nj] == '*' || bfscheck[ni][nj] == true)
			continue;

		bfscheck[ni][nj] = true;

		if (tmpgraph[ni][nj] == 'm') {
			pair <int, int> tmp = changeDirection(front.direction);
			q.push(node(ni, nj, tmp.first));
			q.push(node(ni, nj, tmp.second));
		}
		else {
			q.push(node(ni, nj, front.direction));
		}
	}
	return false;
}

class bfsNode {
public:
	int index;
	char graph[51][51];

	bfsNode(int index) {
		this->index = index;
	}
};

void settmpgraph(char graph[51][51]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmpgraph[i][j] = graph[i][j];
		}
	}
}
int bfs() {
	queue <bfsNode> q;

	bfsNode init = bfsNode(-1);
	memcpy(init.graph, graph, sizeof(graph));

	q.push(init);

	int length = 0;

	while (q.size()) {

		int s = q.size();

		for (int qs = 0; qs < s; qs++) {
			bfsNode front = q.front();

			q.pop();

			settmpgraph(front.graph);

			if (checkIfAnswer())
				return length;


			for (int i = front.index + 1; i < mirror.size(); i++) {
				front.graph[mirror[i].first][mirror[i].second] = 'm';
				front.index = i;
				q.push(front);
				front.graph[mirror[i].first][mirror[i].second] = '!';
			}
		}
		length++;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == '!') {
				mirror.push_back({ i,j });
			}
			else if (graph[i][j] == '#') {
				doors.push_back({ i,j });
			}
		}
	}
	cout << bfs();
	//system("Pause");
}