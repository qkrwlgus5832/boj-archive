#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;


int graph[5][5];
int dir[4][2] = { {-1, 0}, {1,0}, {0, -1}, {0, 1} };

set <int> s;

void recursion(int i1, int j1, int index ,int value) {
	if (index == 6) {
		if (s.find(value) == s.end()) {
			s.insert(value);
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ni = i1 + dir[i][0];
		int nj = j1 + dir[i][1];
		if (ni < 0 || nj < 0 || ni >= 5 || nj >= 5)
			continue;
		int nvalue = value * 10 + graph[ni][nj];
		recursion(ni, nj, index + 1, nvalue);
	}
}

int main() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> graph[i][j];
		}
	}
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			recursion(i, j, 0, 0);
		}
	}
	cout << s.size();
	//system("Pause");
}