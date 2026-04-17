#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int M;

int graph[400][400];
int graphc[400][400];
bool check[101][101];
queue <int> q;

vector <int> v;
void cango(int x, int y);

void bfs(int x, int y)
{
	q.push(x*M + y);
	check[x][y] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int x2 = now / M;
		int y2 = now%M;
		cango(x2, y2);
	}

}

void melting(int x, int y) {
	if (y < M - 1 && graph[x][y + 1] >=1) {
		graph[x][y + 1] = graph[x][y+1] - 1;
	}
	if (y >= 1 && graph[x][y - 1] >=1) {
		graph[x][y - 1] = graph[x][y-1] - 1;
	}

	if (x >= 1 && graph[x - 1][y] >=1) {
		graph[x - 1][y] = graph[x-1][y] - 1;

	}

	if (x<N - 1 &&  graph[x + 1][y] >=1) {
		graph[x+1][y] = graph[x+1][y] - 1;
	}

}

void cango(int x, int y) {
	if (y < M - 1 && graph[x][y + 1] >= 1 && check[x][y + 1] == false) {
		check[x][y + 1] = true;
		q.push(x*M + (y + 1));
	}
	if (y >= 1 && graph[x][y - 1] >= 1 && check[x][y - 1] == false) {
		check[x][y - 1] = true;
		q.push(x*M + (y - 1));
	}

	if (x >= 1 && graph[x - 1][y] >= 1 && check[x - 1][y] == false) {
		check[x - 1][y] = true;
		q.push((x - 1)*M + (y));
	}

	if (x<N - 1 && graph[x + 1][y] >= 1 && check[x + 1][y] == false) {
		check[x + 1][y] = true;
		q.push((x + 1)*M + (y));
	}


}




int main() {

	cin >> N >> M;



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}



	int count = 0;


	while (1) {
		int f = 1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] == 0)
					v.push_back(i*M + j);
			}
		}
		for (int i = 0; i < v.size(); i++) {
			melting(v[i] / M, v[i] % M);
		}
	

		v.clear();
		

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] >= 1)
					f = 0;
			}
		}

		count = count + 1;
		int K = 0;


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] >= 1)
					if (check[i][j] == false) {
						bfs(i, j);
						K = K + 1;
					}
			}
		}

		if (K >= 2) {
			cout << count;
			break;
		}
		else if (f==1){
			cout << 0;
			break;
		}
		else {
		
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					check[i][j] = false;
				}
			}
		}
	}


}
