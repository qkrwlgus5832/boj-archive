#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector <int> graph[100001];
bool check[100001];
int checkLevel[100001];

void BFS() {
	queue <int> q;
	q.push(1);

	check[1] = true;

	int level = 0;

	while (q.size()) {
		int s = q.size();

		for (int qs = 0; qs < s; qs++) {
			int front = q.front();
			checkLevel[front] = level;
			q.pop();

			for (int next : graph[front]) {
				if (check[next] == false) {
					check[next] = true;
					q.push(next);
				}
			}
		}
		level++;
	}
}



int main() {
	int N;
	cin >> N;

	int a, b;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	BFS();

	int input;
	
	int previous = 0;

	bool result = true;


	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if (checkLevel[input] == previous + 1) {
			previous = checkLevel[input];
		}
		else if (checkLevel[input] < previous) {
			result = false;
		}
	}
	cout << result;
	//system("Pause");
}
