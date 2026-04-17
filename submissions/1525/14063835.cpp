#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int graph[3][3];

//string graph;

map <int, char> m;

int dir[4][2] = { {-1, 0} , {1, 0}, {0, -1}, {0, 1} };

class node {
public:
	int puzzlei;
	int puzzlej;
	string puzzle;
};


int makecheck(queue <node>& q, int ni, int nj, string puzzle) {
	int count = 0;
	for (int i = 0; i < 9; i++) {
		count *= 10;
		count += puzzle[i] - '0';
	}
	if (count == 123456780)
		return true;
	if (m.find(count) == m.end()) {
		m[count] = '0';
		node tmp;
		tmp.puzzlei = ni; tmp.puzzlej = nj; tmp.puzzle = puzzle;
		q.push(tmp);
	}
	return false;
}


int BFS(int i, int j, string puzzle) {
	queue <node> q;

	int time = 0;
	if (makecheck(q, i, j, puzzle))
		return time;

	while (!q.empty()) {
		int s = q.size();
		for (int i1 = 0; i1 < s; i1++) {
			int fronti = q.front().puzzlei;
			int frontj = q.front().puzzlej;
			string puzzle2 = q.front().puzzle;
			string tmppuzzle = puzzle2;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ni = fronti + dir[i][0];
				int nj = frontj + dir[i][1];
				if (ni < 0 || nj < 0 || ni >= 3 || nj >= 3)
					continue;
				swap(puzzle2[ni * 3 + nj], puzzle2[fronti * 3 + frontj]);
				if (makecheck(q, ni, nj , puzzle2))
					return time + 1;
				puzzle2 = tmppuzzle;
				}
		}
		time++;
	}
	return -1;
}


int main() {
	pair <int, int> startlocation;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) {
				startlocation.first = i;
				startlocation.second = j;
			}
		}
	}
	string puzzle = "";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char dd = graph[i][j] + '0';
			puzzle += dd;
		}
	}
	cout << BFS(startlocation.first, startlocation.second, puzzle);

	//system("Pause");
}