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
		for (int i = count; i < n; i++) {
			for (int i1 = 1; i1 < n - i; i1++) {
				if (a[i][j] == a[i + i1][j]) {
					graph[i][j] = graph[i][j] + 1;
					graph[i + i1][j] = graph[i + i1][j] + 1;
				}

			}
		}
	}


	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			graph[i][5] = graph[i][5] + graph[i][j];
		}
	}
	int a2 = graph[0][5];
	for (int i = 1; i < n; i++) {
		if (a2 <= graph[i][5])
			a2 = graph[i][5];
	}

	for (int i = 0; i < n; i++) {
		if (a2 == graph[i][5]) {
			cout << i+1;
			break;
		}
	}
}