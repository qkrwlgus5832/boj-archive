#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


bool graph[10001][10001];
int N, M;
vector <pair <int,int>> v;


bool compare(pair <int, int> a, pair <int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}
void BFS(int node) {
	bool check[10001] = { false, };
	queue<int> q;
	q.push(node);
	check[node] = true;
	int count = 0;
	while (!q.empty()) {
		int frontnode = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (graph[frontnode][i] == true && check[i] == false) {
				check[i] = true;
				q.push(i);
				v[i].first++;
			}
		}
	}
	
}


int main() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
	}
	v.resize(10001);
	for (int i = 1; i <= N; i++) {
		v[i].second = i;
	}
	for (int i = 1; i <= N; i++) {
		BFS(i);
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == v[0].first) {
			printf("%d ", v[i].second);
		}
	}
	//system("Pause");
}