#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <queue>
using namespace std;

queue <pair<pair<int, int> , pair <char , int >>> q;

char graph[501][501];
char graph2[501][501];
bool check[501][501][4];
int N, M;

int result;

int recursion(int x, int y, char dir, int distance) {
	q.push(make_pair(make_pair(x, y), make_pair(dir, distance)));
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		dir = q.front().second.first;
		distance = q.front().second.second;
		q.pop();
		if (dir == 'U') {
			if (graph[x][y] == '/')
				dir = 'R';
			else if (graph[x][y] == 92)
				dir = 'L';
		}

		else if (dir == 'R') {
			if (graph[x][y] == '/')
				dir = 'U';
			else if (graph[x][y] == 92)
				dir = 'D';
		}
		else if (dir == 'D') {
			if (graph[x][y] == '/')
				dir = 'L';
			else if (graph[x][y] == 92)
				dir = 'R';
		}

		else if (dir == 'L') {
			if (graph[x][y] == '/')
				dir = 'D';
			else if (graph[x][y] == 92)
				dir = 'U';
		}
		if (dir == 'U')
			check[x][y][0] = 1;
		else if (dir == 'R') {
			check[x][y][1] = 1;
		}
		else if (dir == 'D')
			check[x][y][2] = 1;
		else if (dir == 'L')
			check[x][y][3] = 1;
		if (dir == 'U') {
			if (x - 1 >= 1 && check[x - 1][y][0] == 0 && (graph[x - 1][y] != 'C'))
				q.push(make_pair(make_pair(x - 1, y), make_pair(dir, distance + 1)));
			else if (x - 1 >= 1 && check[x - 1][y][0] >= 1)
				return -1;
			else if (x - 1 >= 1 && graph[x - 1][y] == 'C')
				break;
		}
		else if (dir == 'R') {
			if (y + 1 <= M &&  check[x][y + 1][1] == 0 && graph[x][y + 1] != 'C')
				q.push(make_pair(make_pair(x, y + 1), make_pair(dir, distance + 1)));
			else if (y + 1 <= M &&  check[x][y + 1][1] >= 1)
				return -1;
			else if (y + 1 <= M && graph[x][y + 1] == 'C')
				break;
		}
		else if (dir == 'D') {
			if (x + 1 <= N && check[x + 1][y][2] == 0 && graph[x + 1][y] != 'C')
				q.push(make_pair(make_pair(x + 1, y), make_pair(dir, distance + 1)));
			else if (x + 1 <= N &&  check[x + 1][y][2] >= 1)
				return -1;
			else if (x + 1 <= N && graph[x + 1][y] == 'C')
				break;
		}
		else if (dir == 'L') {
			if (y - 1 >= 1 && check[x][y - 1][3] == 0 && graph[x][y - 1] != 'C')
				q.push(make_pair(make_pair(x, y - 1), make_pair(dir, distance + 1)));

			else if (y - 1 >= 1 && check[x][y - 1][3] >= 1)
				return -1;
			else if (y - 1 >= 1 && graph[x][y - 1] == 'C')
				break;
		}

	}

	return distance;
}

void mems() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			graph[i][j] = graph2[i][j];
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> graph2[i][j];
		}
	}





	int PR, PC;
	cin >> PR >> PC;

	int max1 = -1;
	int f = 0;



	mems();
	char tmp;



	 result = recursion(PR, PC, 'U', 1);

	if (result != -1) {
		max1 = result;
		tmp = 'U';
	}

	else {
		cout << 'U' << endl;
		cout << "Voyager";
		f = 1;
	}

	mems();
	

	result = recursion(PR, PC, 'R', 1);
	if (f == 0) {
		if (result != -1) {
			if (result > max1) {
				max1 = result;
				tmp = 'R';
			}

	
		}
		else if (f==0) {
			cout << 'R' << endl;
			cout << "Voyager";
			f = 1;

		}
	}
	mems();

	result = recursion(PR, PC, 'D', 1);
	if (f == 0) {
		if (result != -1) {
			if (result > max1) {
				max1 = result;
				tmp = 'D';
			}
		
		}

		else if (f == 0) {
			cout << 'D' << endl;
			cout << "Voyager";
			f = 1;
		}
	}
	mems();
	result = recursion(PR, PC, 'L', 1);
	if (f == 0) {
		if (result != -1) {
			if (result > max1) {
				max1 = result;
				tmp = 'L';
			}

		}

		else if (f == 0) {
			cout << 'L' << endl;
			cout << "Voyager";
			f = 1;
		}
	}
	mems();
	if (f == 0) {
		cout << tmp << endl;
		cout << max1;
	}

}