#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int graph[51][51];
int N, M;
int r, c, d;
queue <pair<pair<int, int>,int>> q;
bool check[51][51];

int result = 0;
void recursion(int x, int y, int d, int flag) {
	if (check[x][y] == false) {
		result++;
	
	}

	check[x][y] = true;

	
	if (d == 0) {
		if (y - 1 >= 0 && graph[x][y - 1] == 0 && check[x][y - 1] == 0) {
			recursion(x, y - 1, 3, 0);
		}
		else {
			if (flag == 4) {
				if (x + 1 < M && graph[x + 1][y] == 0)
					recursion(x + 1, y, d, 0);
				else
					return;

			}
			else
			recursion(x, y, 3, flag + 1);

		}
		return;
	}

			
	else if (d == 1) {
		if (x - 1 >= 0 && graph[x - 1][y] == 0 && check[x - 1][y] == 0) {
			recursion(x - 1, y, 0, 0);
		}
		else {
			if (flag == 4) {
				if (y - 1 >= 0 && graph[x][y - 1] == 0) {
					recursion(x, y - 1, d, 0);
				}
				else
					return;
			}
			else
			recursion(x, y, 0, flag + 1);
		}

		return;
	}


	else if (d == 2) {
		if (y + 1 < N&& graph[x][y + 1] == 0 && check[x][y + 1] == 0) {
			recursion(x, y + 1, 1, 0);
		}
		else {
			if (flag == 4) {
				if (x - 1 >= 0 && graph[x - 1][y] == 0) {
					recursion(x - 1, y, d, 0);
				}
				else
					return;
			}
			else
			recursion(x, y, 1, flag + 1);
		}

		return;
	}
	else if (d == 3) {
		if (x + 1 < M && graph[x + 1][y] == 0 && check[x + 1][y] == 0) {
			recursion(x + 1, y, 2, 0);
		}
		else {
			if (flag == 4) {
				if (y + 1 < N && graph[x][y + 1] == 0)
					recursion(x, y + 1, d, 0);
				else
					return;
			}

		else
		recursion(x, y, 2, flag + 1);
		}


	}
	return;

}






int main() {
	cin >> M >> N;
	cin >> r >> c >> d;


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		
		}
	}


	recursion(r, c, d, 0);
	cout << result;

}