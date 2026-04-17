#define _CRT_SECURE_NO_WRANINGS
#include <iostream>
#include <algorithm>

using namespace std;

bool graph[101][101];

bool dist[10001][10001];

int N;

void floid() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				graph[i][j] = (graph[i][j] || (graph[i][k] && graph[k][j]));
			}
		}
	}
}


int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			//dist[i * N + j] = true;
		}
	}

	floid();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	//system("Pause");
}