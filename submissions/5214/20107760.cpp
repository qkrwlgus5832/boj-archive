#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K, M;

vector <int> v[100001];


int BFS(int i) {
	bool check[100001] = { false, };

	check[i] = true;
	queue <int> q;

	q.push(i);

	int level = 1;

	while (q.size()) {
		int s = q.size();
		for (int qs = 0; qs < s; qs++) {
			int front = q.front();
			q.pop();

			if (front == N) {
				return level;
			}
			for (int i = 0; i < v[front].size(); i++) {
				if (check[v[front][i]] == false) {
					check[v[front][i]] = true;
					q.push(v[front][i]);
				}
			}

		}
		level++;
	}
	return -1;
}
int main() {

	cin >> N >> K >> M;
	int tmp;
	for (int i = 0; i < M; i++) {
		vector <int> input;
		for (int j = 0; j < K; j++) {
			scanf("%d", &tmp);
			input.push_back(tmp);
		}
		sort(input.begin(), input.end());
		for (int j = 1; j < K; j++) {
			v[input[0]].push_back(input[j]);
		}

	}

	cout << BFS(1);
	//system("Pause");

}