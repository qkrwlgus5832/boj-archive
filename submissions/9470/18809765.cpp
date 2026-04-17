#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int topologicalSort(int M, int depth[1001], vector <int> graph[1001]) {
	queue <int> q;


	pair <int, int> check[1001];

	int Strahler[1001] = { 0, };

	for (int i = 1; i <= M; i++) {
		if (depth[i] == 0) {
			q.push(i);
			Strahler[i] = 1;
		}
	}

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		if (check[front].second == 1){
			Strahler[front] = check[front].first;
		}
		else if (check[front].second > 1) {
			Strahler[front] = check[front].first + 1;
		}

		for (int i = 0; i < graph[front].size(); i++) {

			if (--depth[graph[front][i]] == 0) {
			
				q.push(graph[front][i]);
			}
			if (check[graph[front][i]].first < Strahler[front]) {
				check[graph[front][i]].first = Strahler[front];
				check[graph[front][i]].second = 1;
			}
			else if (check[graph[front][i]].first == Strahler[front]) {
				check[graph[front][i]].second++;
			}

		}
	}
	return Strahler[M];

}
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int K, M, P;
	
		int depth[1001] = { 0, };

		vector <int> graph[1001];
		scanf("%d %d %d", &K, &M, &P);

		int A, B;
		for (int i = 0; i < P; i++) {
			scanf("%d %d", &A, &B);
			graph[A].push_back(B);
			depth[B]++;
		}
		printf("%d %d\n", K, topologicalSort(M, depth, graph));
	}

	//system("Pause");
}