#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>
using namespace std;


char graph[501][501];
char graph2[501][501];
int N, M;


int recursion(int x, int y, char dir, int distance) {

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
	graph[x][y] = '*';
	if (dir == 'U') {
		if (x >= 1 && ( graph[x - 1][y] == '.' || graph[x - 1][y] == '/' || graph[x - 1][y] == 92 ) )
			return recursion(x - 1, y, dir, distance + 1);
		else if (x >= 1 && graph[x - 1][y] == '*')
			return -1;
		else
			return distance;
	}
	else if (dir == 'R') {
		if (y + 1 <= M && (graph[x][y+1] == '.' || graph[x][y+1] == '/' || graph[x][y+1] == 92) )
			return recursion(x, y + 1, dir, distance + 1);
		else if (y + 1 <= M && graph[x][y + 1] == '*')
			return -1;
		else
			return distance;
	}
	else if (dir == 'D') {
		if (x + 1 <= N && (graph[x +1][y] == '.' || graph[x +1][y] == '/' || graph[x + 1][y] == 92))
			return recursion(x + 1, y, dir, distance + 1);
		else if (x + 1 <= N && graph[x + 1][y] == '*')
			return -1;
		else
			return distance;
	}
	else if (dir == 'L') {
		if (y - 1 >= 1 && (graph[x][y-1] == '.' || graph[x][y-1] == '/' || graph[x][y-1] == 92))
			return recursion(x, y - 1, dir, distance + 1);
		else if (y - 1 >= 1 && graph[x][y - 1] == '*')
			return -1;
		else
			return distance;

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
	int result = recursion(PR, PC, 'U', 1);

	if (result != -1) {
		max1 = result;
		tmp = 'U';
	}

	else {
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
		else {
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