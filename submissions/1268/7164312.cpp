#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int graph[1000][1000];
int a[1000][1000];
queue <int> q;
int n;



int main() {
	cin >> n;
	int b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> b;
			a[i][j] = b;
		}
	}

	int count = 0;
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < n; i++) {
			for (int i1 = 0; i1 < n; i1++) {
				if (a[i][j] == a[i1][j] && i != i1) {
					graph[i][i1] = 1;
					graph[i1][i] = 1;

				}

			}
		}
	}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][n] = graph[i][n] + graph[i][j];
		}
	}
	int a2 = graph[0][n];
	for (int i = 1; i < n; i++) {
		if (a2 <= graph[i][n])
			a2 = graph[i][n];
	}

	for (int i = 0; i < n; i++) {
		if (a2 == graph[i][n]) {
			cout << i + 1;
			break;
		}
	}
}