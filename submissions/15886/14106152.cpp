#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N, M;

int result = -1;

char graph[1001];

int check[1001];

int dir[2] = { -1, 1 };


int queuepush( int nx, queue <int>& q, int tmp) {
	if (check[nx] != 0) {
		if (check[nx] == tmp)
			return 1;
		else
			return -1;
	}
	check[nx] = tmp;
	q.push(nx);
	return 0;
}


int BFS(int i , int tmp) {
	
	queue <int> q;
	q.push(i);
	//check2[i][j] = true;
	check[i] = tmp;
	while (!q.empty()) {
		int fronti = q.front();

		q.pop();

		 if(graph[fronti] == 'W') {
			int nx = fronti + dir[0];
		
			if (queuepush( nx,  q, tmp) == 1)
				return 1;
			if (queuepush( nx, q, tmp) == -1)
				return 0;
		}
		else if (graph[fronti] == 'E') {
			int nx = fronti + dir[1];
		
			if (queuepush(nx, q, tmp) == 1)
				return 1;
			if (queuepush(nx, q, tmp) == -1)
				return 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> graph[i];
		
	}
	int result = 0;
	int tmp = 1;
	for (int i = 0; i < N; i++) {
		if (check[i]== false) {
			result += BFS(i, tmp);
			tmp++;
		}
	}
	cout << result;
	//system("Pause");
}