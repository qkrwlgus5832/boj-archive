#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

queue <int> q;

bool check[1000][1000];

char graph[1000][1000];

int N, M;


void BFS(int x, int y) {
	q.push(x*M+y);
	while (!q.empty()) {
		int x1 = q.front() / M;
		int y1 = q.front() % M;
		check[x1][y1] = true;
		q.pop();
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
				BFS(i, j);
				result++;
			}
		}
	}
	cout << result;
}