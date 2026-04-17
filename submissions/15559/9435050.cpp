#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

queue <int> q;

int check2[1001][1001];

char graph[1001][1001];

int N, M;

int BFScycle(int x, int y) {
	bool check[1001][1001] = { false, };
	q.push(x*M+y);
	int count = 0;
	while (!q.empty()) {
		int x1 = q.front() / M;
		int y1 = q.front() % M;
		q.pop();
		count++;
		check2[x1][y1] = count;
		check[x1][y1] = true;

		if (graph[x1][y1] == 'S') {
			if (check[x1 + 1][y1] == true) {
				count = check2[x1+1][y1];
				break;
			}
			else if (check2[x1+1][y1] == 0)
			q.push((x1 + 1)*M + y1);

		}
		else if (graph[x1][y1] == 'E' ) {
			if (check[x1][y1 + 1] == true) {
				count = check2[x1][y1 + 1];
				break;
			}
			else if (check2[x1][y1+1] ==0)
			q.push(x1*M + y1 + 1);
			
		}
		else if (graph[x1][y1] == 'N') {
			if (check[x1 - 1][y1] == true) {
				count = check2[x1 - 1][y1];
				break;
			}
			else if (check2[x1-1][y1] ==0)
			q.push((x1 - 1)*M + y1);
			
		}
		else if (graph[x1][y1] == 'W') {
			if (check[x1][y1 - 1] == true) {
				count = check2[x1][y1 - 1];
				break;
			}
			else if (check2[x1][y1-1] == 0)
			q.push((x1)*M + y1 - 1);
			
		}
	}

	return count;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}


	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check2[i][j] == 0) {
				result += BFScycle(i, j);
			}
		}
	}
	cout << result;
}