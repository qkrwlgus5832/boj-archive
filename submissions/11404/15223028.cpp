#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int graph[101][101];

int N;

void floid() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				if (i == j)
					continue;
				if (graph[i][k] == 0 || graph[k][j] == 0) {
					continue;
				}

				if (graph[i][j] == 0) {
					graph[i][j] = graph[i][k] + graph[k][j];
					continue;
				}


				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

int main() {
	int M;
	cin >> N;
	cin >> M;

	int a, b, cost;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> cost;
		if (graph[a][b] == 0)
			graph[a][b] = cost;
		else
			graph[a][b] = min(graph[a][b], cost);

	}
	floid();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	//cout << endl;
	//system("Pause");
}