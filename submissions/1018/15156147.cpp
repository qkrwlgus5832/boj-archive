#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int N, M;

char graph[51][51];

char tmpgraph[51][51];

char change(char gr) {
	if (gr == 'W') {
		return 'B';
	}
	else if (gr == 'B') {
		return 'W';
	}
}


int main() {
	
	int result = -1;
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + 7 >= N || j + 7 >= M)
				continue;
			int count = 0;
			memcpy(tmpgraph, graph, sizeof(graph));
			for (int i1 = 0; i1 < 7; i1++) {
				for (int j1 = 0; j1 < 8; j1++) {
					if (j1+1 < 8 && tmpgraph[i + i1][j + j1] == tmpgraph[i + i1][j + j1 + 1]) {
						tmpgraph[i + i1][j + j1 + 1] = change(tmpgraph[i + i1][j + j1 + 1]);
						count++;
					}
					if (i1 + 1< 8 && tmpgraph[i + i1 + 1][j + j1] == tmpgraph[i + i1][j + j1]) {
						tmpgraph[i + i1 + 1][j + j1] = change(tmpgraph[i + i1 + 1][j + j1]);
						count++;
					}
				}
			}


			if (result == -1)
				result = count;
			else
				result = min(result, count);
			
			count = 1;

			memcpy(tmpgraph, graph, sizeof(graph));
			tmpgraph[i][j] = change(tmpgraph[i][j]);
			for (int i1 = 0; i1 < 7; i1++) {
				for (int j1 = 0; j1 < 8; j1++) {

					if (j1 + 1 < 8 && tmpgraph[i + i1][j + j1] == tmpgraph[i + i1][j + j1 + 1]) {
						tmpgraph[i + i1][j + j1 + 1] = change(tmpgraph[i + i1][j + j1 + 1]);
						count++;
					}
					if (i1 + 1 < 8 && tmpgraph[i + i1 + 1][j + j1] == tmpgraph[i + i1][j + j1]) {
						tmpgraph[i + i1 + 1][j + j1] = change(tmpgraph[i + i1 + 1][j + j1]);
						count++;
					}

				}
			}
			result = min(result, count);

		}
	}
	cout << result;
	//system("Pause");
}