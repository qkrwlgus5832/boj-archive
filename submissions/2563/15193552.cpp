#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool graph[101][101];
int main() {
	int T;
	//cin >> T;
	//for (int i = 0; i < T; i++) {
		int N, a, b;

		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> a >> b;
			for (int i1 = 0; i1 < 10; i1++) {
				for (int j1 = 0; j1 < 10; j1++) {
					graph[a + i1][b + j1] = true;
				}
			}
		}

		int sum = 0;
		for (int i1 = 0; i1 < 100; i1++) {
			for (int j1 = 0; j1 < 100; j1++) {
				if (graph[i1][j1] == true) {
					sum += 1;
				}
			}
		}
		memset(graph, false, sizeof(graph));
		cout << sum << endl;
	//}
}