#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>


using namespace std;

vector <int> v[101];
vector <int> v2[101];

bool* BFS(int i, vector <int> v[101], bool check[101]) {
	queue <int> q;
	check[i] = true;

	q.push(i);

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i1 = 0; i1 < v[front].size(); i1++) {
			if (check[v[front][i1]] == false) {
				check[v[front][i1]] = true;
				q.push(v[front][i1]);
			}
		}
	}
	return check;
}



int main() {
	int N;
	int M;
	cin >> N;
	cin >> M;
	int a, b;


	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v2[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		bool check[101] = { false, };
		int count = 0;

		BFS(i, v2, BFS(i, v, check));

		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			else if (check[j] == false) {
				count++;
			}
		}
		printf("%d\n", count);
	}
	//system("Pause");
}