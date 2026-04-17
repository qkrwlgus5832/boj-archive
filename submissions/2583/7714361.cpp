#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int graph[1000][1000]; 
int check[1000][1000];
int M;
int N;
int K;
queue <int> q;
vector <int> v;
int cango(int x, int y, int count);
int bfs(int x,int y) {
	int count = 1;
	q.push(x*N + y);
	check[x][y] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int x2 = now / N;
		int y2 = now%N;
		int a = cango(x2, y2 , count);
		count = a;
	}

	return count;
}

int cango(int x, int y, int count) {

	if (y < N - 1 && graph[x][y + 1] == 0 && check[x][y + 1] == 0) {
		check[x][y + 1] = 1;
		count++;
		q.push(x*N + (y + 1));
	}
	if (y >= 1 && graph[x][y - 1] == 0 && check[x][y - 1] == 0) {
		check[x][y - 1] = 1;
		count++;
		q.push(x*N + (y - 1));
	}

	if (x >= 1 && graph[x - 1][y] == 0 && check[x - 1][y] == 0) {
		check[x - 1][y] = 1;
		count++;
		q.push((x - 1)*N + (y));
	}


	if (x<M - 1 && graph[x + 1][y] == 0 && check[x + 1][y] == 0) {
		check[x + 1][y] = 1;
		count++;
		q.push((x + 1)*N + (y));
	}
	
	return count;
}




int main() {
	cin >> M >> N >> K;
	int x;
	int y;
	int x1;
	int y1;
	int K2 = 0;
	for (int i = 0; i < K; i++) {
		cin >> x >> y >> x1 >> y1;
		for (int i = M - y1; i < M-y; i++) {
			for (int j = x; j < x1; j++) {
				graph[i][j] = 1;
			}
		}
		for (int i = 0; i < M ; i++) {
			for (int j = 0; j < N; j++) {
				cout << graph[i][j]<< " " ;
			}
			cout << endl;
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == 0) {
				if (check[i][j] == 0) {
					v.push_back(bfs(i, j));
					K2 = K2+ 1;
				}
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			graph[i][j] = 0;
			check[i][j] = 0;
		}
	}

	cout << K2 << endl;
	
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}

