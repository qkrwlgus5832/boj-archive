#define _CRT_SECURE_NO_WRANINGS
#include <iostream>
#include <vector>
#include <memory.h>
#include <limits.h>
#include <queue>
#include <algorithm>

using namespace std;

int minlength = INT_MAX;
vector < pair <int, int>> v[501];

bool check[501][501];
bool tmpcheck[501][501];
bool dfscheck[501];

void DFS(int start, int end, int length) {
	if (start == end) {
		if (length < minlength) {
			memcpy(check, tmpcheck, sizeof(check));
			minlength = length;
		}
		return;
	}
	for (int i = 0; i < v[start].size(); i++) {
		if (dfscheck[start] == false) {
			tmpcheck[start][v[start][i].first] = true;
			dfscheck[start] = true;
			DFS(v[start][i].first, end, length + v[start][i].second);
			dfscheck[start] = false;
			tmpcheck[start][v[start][i].first] = false;

		}
	}
}

int BFS(int start, int end) {
	queue <pair <int,int>> q;
	bool bfscheck[501] = { false, };
	q.push(make_pair(start, 0));
	bfscheck[start] = true;
	int returnvalue = INT_MAX;
	while (!q.empty()) {
		int front = q.front().first;
		int length = q.front().second;
		q.pop();
		if (front == end) {
			returnvalue = min(returnvalue, length);
			continue;
		}
		for (int i = 0; i < v[front].size(); i++) {
			if (check[front][v[front][i].first] == false && bfscheck[v[front][i].first] == false) {
				bfscheck[v[front][i].first] = true;
				q.push(make_pair(v[front][i].first , length + v[front][i].second));
			}
		}
	}
	if (returnvalue == INT_MAX)
		return -1;
	else
		return returnvalue;
}

void setchecksfalse() {
	memset(check, false, sizeof(check));
	memset(tmpcheck, false, sizeof(tmpcheck));
	memset(dfscheck, false, sizeof(dfscheck));

}
int main() {
	int place, road;

	while (1) {
		for (int i = 0; i < 500; i++) {
			v[i].clear();
		}

		cin >> place >> road;
		if (place == 0 && road == 0)
			break;
		int start, end;
		cin >> start >> end;
		int U, V, P;
		for (int i = 0; i < road; i++) {
			cin >> U >> V >> P;
			v[U].push_back(make_pair(V, P));
		}
		minlength = INT_MAX;
		
		setchecksfalse();

		DFS(start, end, 0);

		cout << BFS(start, end) << endl;
	}
}