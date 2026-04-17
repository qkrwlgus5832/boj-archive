#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

vector <int> v[100001];

bool check[100001];

int BFS(int i) {
	int cyclecheck[100001] = { 0, };
	queue <int> q;
	q.push(i);
	int count = 1;
	cyclecheck[i] = count;
	check[i] = true;

	while (!q.empty()) {
		int fronti = q.front();
		q.pop();
		if (cyclecheck[v[fronti][0]] == 0 && check[v[fronti][0]] == false) {
			cyclecheck[v[fronti][0]] = ++count;
			q.push(v[fronti][0]);
			check[v[fronti][0]] = true;
		}
		else if (cyclecheck[v[fronti][0]] != 0) {
			return count - (cyclecheck[v[fronti][0]] - 1);
		}
	}
	return 0;
}

void clear() {
	for (int i = 1; i <= 100000; i++) {
		v[i].clear();
	}
}
int main() {
	int T;
	int n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		int tmp;
		clear();
		for (int j = 1; j <= n; j++) {
			scanf("%d", &tmp);
			v[j].push_back(tmp);
		}
		memset(check, false, sizeof(check));
		int count = 0;
		for (int j = 1; j <= n; j++) {
			if (check[j] == false) {
				count += BFS(j);
			}
		}
		printf("%d\n", n - count);
	}
	//system("Pause");
}