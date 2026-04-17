#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int N;
int M;
int V;
int graph[2000][2000];
int check[2000];
int check2[2000];

queue <int> q;
queue <int> inject;
stack <int> st;

void BFS(int n) {
	q.push(n);
	check[n] = 1;

	while (!q.empty()) {
		int n1 = q.front();
		inject.push(n1);
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (graph[i][n1] == 1 && check[i] == 0) {
				q.push(i);
				check[i] = 1;
			}
		}

	}
}


void DFS(int n) {
	st.push(n);
	check[n] = 1;

	while (!st.empty()) {
		int n1 = st.top();
		if (check2[n1] == 0) {
			inject.push(n1);
			check2[n1] = 1;
		}

		int f = 0;
		
		for (int i = 1; i <=N; i++) {
			if (graph[i][n1] == 1 && check[i] == 0) {
				st.push(i);
				check[i] = 1;
				f = 1;
				break;
			}
		}
		if (f == 0)
			st.pop();
	}

}



int main() {
	cin >> N >> M >> V;
	int a;
	int b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;

	}



	
	for (int i = 1; i <= N; i++) {
		if (check[i] == 0)
			DFS(i);
	}
	int a2 = inject.size();

	for (int i = 0; i < a2; i++) {
		cout << inject.front() << " ";
		inject.pop();
	}
	for (int i = 1; i <= N; i++) {
		check[i] = 0;

	}

	for (int i = 1; i <= N; i++) {
		if (check[i] == 0)
			BFS(i);
	}
	cout << endl;
	int a1 = inject.size();
	for (int i = 0; i < a1; i++) {
		cout << inject.front() << " ";
		inject.pop();
	}
}
