#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>

using namespace std;

int dir[4][2] = { {-1,0},{1,0}, {0,-1},{0,1} };
int curveddir[4][2] = {
	{'l', 'r'},
	{'r', 'l'},
	{'d','u' },
	{'u', 'd'}
};

int getDirIndex(char x) {
	if (x == 'u') {
		return 0;
	}
	if (x == 'd')
		return 1;
	if (x == 'l')
		return 2;
	if (x == 'r')
		return 3;
}
int rectangle[4] = { 0,0, 0, 0 };

void recursion(int i, int j, string input, int count, int direction) {
	rectangle[0] = max(rectangle[0], i);
	rectangle[1] = max(rectangle[1], j);
	rectangle[2] = min(rectangle[2], i);
	rectangle[3] = min(rectangle[3], j);

	if (count >= input.size())
		return;

	if (input[count] == 'F') {
		int ni = i + dir[direction][0];
		int nj = j + dir[direction][1];

		recursion(ni, nj, input, count + 1, direction);
	}
	if (input[count] == 'B') {
		int ni = i + dir[direction][0] * -1;
		int nj = j + dir[direction][1] * -1;

		recursion(ni, nj, input, count + 1, direction);
	}
	if (input[count] == 'L') {
		direction = getDirIndex(curveddir[direction][0]);
		recursion(i, j, input, count + 1, direction);

	}
	if (input[count] == 'R') {
		direction = getDirIndex(curveddir[direction][1]);
		recursion(i, j, input, count + 1, direction);
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		string input;
		cin >> input;
		memset(rectangle, 0, sizeof(rectangle));
		recursion(0, 0, input, 0, 0);
		int xSize = rectangle[0] - rectangle[2];
		int ySize = rectangle[1] - rectangle[3];

		printf("%d\n", xSize * ySize);
	}
//	system("Pause");
}
