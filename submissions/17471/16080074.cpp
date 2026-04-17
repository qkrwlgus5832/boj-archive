#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;


int N;

vector <int> People;
vector <int> graph[11];
int result = -1;

bool check[11];


bool bfs(int represent, int findindex) {
	queue <int> q;
	bool bfscheck[11] = { false, };
	q.push(represent);
	bfscheck[represent] = true;

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		if (front == findindex)
			return true;
		for (int i = 0; i < graph[front].size(); i++) {
			if (check[graph[front][i]] == false && bfscheck[graph[front][i]] == false) {
				q.push(graph[front][i]);
				bfscheck[graph[front][i]] = true;
			}
		}
	}
	return false;
}


bool checkIfAnswer() {
	int represent = -1;
	for (int i = 0; i < N; i++) {
		if (check[i] == false) {
			if (represent == -1) {
				represent = i;
				continue;
			}
			if (bfs(represent, i) == false)
				return false;
		}
	}
}


void recursion(int index, int represent) {
	if (checkIfAnswer()) {
		int count1 = 0; int count2 = 0;
		for (int i = 0; i < N; i++) {
			if (check[i] == true)
				count1 += People[i];
			else
				count2 += People[i];
		}
		if (result == -1)
			result = INT_MAX;
		result = min(result, abs(count1 - count2));
	}

	for (int i = 0; i < graph[represent].size(); i++) {
		if (check[graph[represent][i]] == false && graph[represent][i] > represent) {
			check[graph[represent][i]] = true;
			recursion(0, graph[represent][i]);
			recursion(graph[represent][i], represent);
			check[graph[represent][i]] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int tmp;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		People.push_back(tmp);
	}

	int number;

	for (int i = 0; i < N; i++) {
		cin >> number;
		for (int j = 0; j < number; j++) {
			cin >> tmp;
			graph[i].push_back(--tmp);
		}
	}


	for (int i = 0; i < N; i++) {
		memset(check, false, sizeof(check));
		check[i] = true;
		recursion(i, i);
		check[i] = false;
	}
	cout << result;
//	system("Pause");
}