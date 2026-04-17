#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>

using namespace std;
int R, C;
char graph[21][21];
map<char, int> alphabet;
int dir[4][2] = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };

int recursion(int x, int y, int count) {
	alphabet.insert(make_pair(graph[x][y], 1));
	int nx, ny;
	for (int i = 0; i < 4; i++) {
	
			 nx = x + dir[i][0];
			 ny = y + dir[i][1];
		
			if (nx >=0 && nx < R && ny >=0 && ny < C) {
				if (alphabet.count(graph[nx][ny]) == 0)
					return recursion(nx, ny, count + 1);
			}

		}
	
	return count;
}





int main() {


	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> graph[i][j];
		}
	}


	cout<<recursion(0, 0, 1);

}