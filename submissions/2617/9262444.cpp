#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;


int N;
int M;


int graph[100][100];
 


int BFS1(int x) {
	queue <int> q;
	int check[100] = { false, };
	q.push(x);
	int count = 0;

	while (!q.empty()) {
		int x1 = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (graph[x1][i] == 1 && check[i] == false) {
				q.push(i);
				check[i] = true;
				count++;
			}

		}

	}

	return count;
}


int BFS2(int x) {
	queue <int> q;
	int check[100] = { false, };
	q.push(x);
	int count = 0;

	while (!q.empty()) {
		int x1 = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (graph[x1][i] == -1 && check[i] == false) {
				q.push(i);
				check[i] = true;
				count++;
			}

		}

	}

	return count;

}





int main() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = -1;

	}




	int left;
	int right;

	if (N % 2 == 1) {
		left = (N + 1) / 2;
		right = (N + 1) / 2;
		
	}
	else {
		left = (N + 1) / 2;
		right = (N + 1) / 2 + 1;
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		if (BFS1(i) >= left || BFS2(i) >= right)
			result++;
	}

	cout << result;
}