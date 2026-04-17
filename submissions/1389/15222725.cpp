#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector <int> v[101];

int BFS(int i) {
	queue <pair <int, int>> q;
	bool check[101] = { false, };
	q.push(make_pair(i, 0));
	check[i] = true;

	int returnvalue = 0;

	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int frontuser = q.front().first;
			int cnt = q.front().second;

			q.pop();

			for (int i1 = 0; i1 < v[frontuser].size(); i1++) {
				if (check[v[frontuser][i1]] == false) {
					check[v[frontuser][i1]] = true;
					returnvalue += cnt + 1;
					q.push(make_pair(v[frontuser][i1], cnt + 1));
				}
			}
		}
	}
	return returnvalue;
}

int main() {
	int N, M;

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	int result = -1;
	int comparevalue = INT_MAX;

	for (int i = 1; i < 101; i++) {
		if (v[i].size() >= 1) {
			int dd = BFS(i);
			if (comparevalue > dd) {
				result = i;
				comparevalue = min(comparevalue, dd);
			}
		}
	}
	cout << result;
	//system("Pause");
}