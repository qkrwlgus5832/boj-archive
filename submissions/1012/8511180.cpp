#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int graph[51][51];
int check[51][51];
queue <int> q;
int N;
int M;
void cango(int x, int y);

void bfs(int x, int y)
{
	q.push(x*N + y);
	check[x][y] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int x2 = now / N;
		int y2 = now%N;
		cango(x2, y2);
	}

}

void cango(int x, int y) {
	int f = 0;
	if (y < N - 1 && graph[x][y + 1] == 1 && check[x][y + 1] == 0) {
		check[x][y + 1] = 1;
		f = 1;
		q.push(x*N + (y + 1));
	}
	if (y >= 1 && graph[x][y - 1] == 1 && check[x][y - 1] == 0) {
		check[x][y - 1] = 1;
		f = 1;
		q.push(x*N + (y - 1));
	}

	if (x >= 1 && graph[x - 1][y] == 1 && check[x - 1][y] == 0) {
		check[x - 1][y] = 1;
		f = 1;
		q.push((x - 1)*N + (y));
	}


	if (x<M - 1 && graph[x + 1][y] == 1 && check[x + 1][y] == 0) {
		check[x + 1][y] = 1;
		f = 1;
		q.push((x + 1)*N + (y));
	}


}



int main() {
	int T;

	int K;
	vector <int> v;
	vector<int> ::iterator vi;

	cin >> T;

	for (int i1 = 0; i1<T; i1++) {
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			int X;
			int Y;
			cin >> X >> Y;
			graph[X][Y] = 1;
		}

		int K1 = 0;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] == 1) {
					if (check[i][j] == 0) {
						bfs(i, j);
						K1 = K1 + 1;
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


		v.push_back(K1);

	}
	for (vi = v.begin(); vi != v.end(); vi++)
		cout << *vi << endl;

}
