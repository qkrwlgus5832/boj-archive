#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

queue <int> q;

bool check[1001][1001];

char graph[1001][1001];

int N, M;


int BFScycle(int x, int y) {
	q.push(x*M+y);
	q.pop();
	int count = 1;
	if (graph[x][y] == 'S' && check[x + 1][y] == false) {
		q.push((x + 1)*M + y);
	}
	else if (graph[x][y] == 'E' && check[x][y + 1] == false) {
		q.push(x*M + y + 1);
	}
	else if (graph[x][y] == 'N' && check[x - 1][y] == false) {
		q.push((x - 1)*M + y);
	}
	else if (graph[x][y] == 'W' && check[x][y - 1] == false) {
		q.push((x)*M + y - 1);

	}
	while (!q.empty()) {
		int x1 = q.front() / M;
		int y1 = q.front() % M;
		check[x1][y1] = true;
		count++;
		q.pop();
		if (x1 == x && y1 == y)
			return 1;	
		if (graph[x1][y1] == 'S' && check[x1+1][y1] == false) {
			q.push((x1 + 1)*M + y1);
		}
		else if (graph[x1][y1] == 'E' && check[x1][y1+1] == false) {
			q.push(x1*M + y1 + 1);
			
		}
		else if (graph[x1][y1] == 'N' && check[x1-1][y1] == false) {
			q.push((x1 - 1)*M + y1);
			
		}
		else if (graph[x1][y1] == 'W' && check[x1][y1-1] == false) {
			q.push((x1)*M + y1 - 1);
			
		}
	}

	return count;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}



	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == false) {
				result += BFScycle(i, j);
			}
		}
	}
	cout << result;
}