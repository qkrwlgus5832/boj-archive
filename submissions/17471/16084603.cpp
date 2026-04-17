#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <map>
using namespace std;


int N;

vector <int> People;
vector <int> graph[11];
int result = -1;

bool check[11];

map <int, int> m;

vector <int> region1;

void bfs(int represent, bool bfscheck[11], bool flag) {
	queue <int> q;
	q.push(represent);
	bfscheck[represent] = true;

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (int i = 0; i < graph[front].size(); i++) {
			if (check[graph[front][i]] == flag && bfscheck[graph[front][i]] == false) {
				q.push(graph[front][i]);
				bfscheck[graph[front][i]] = true;
			}
		}
	}

}

bool regioncheck(bool flag) {
	int represent = -1;
	bool bfscheck[11] = { false, };
	for (int i = 0; i < N; i++) {
		if (check[i] == flag) {
			if (represent == -1) {
				bfs(i, bfscheck, flag);
				break;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (check[i] == flag && bfscheck[i] == false) {
			return false;
		}
	}
}

bool checkIfAnswer() {
	if (regioncheck(true) && regioncheck(false))
		return true;
	else
		return false;
}

void recursion(int count) {
	if (region1.size() == count) {
		if (checkIfAnswer()) {
			int count1= 0;
			int count2 = 0;
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
		return;
	}
	for (int i = 0; i < N; i++) {
		if (check[i] == false) {
			check[i] = true;
			region1.push_back(i);
			recursion(count);
			region1.pop_back();
			check[i] = false;
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


	for (int i = 1; i <= N / 2; i++) {
		memset(check, false, sizeof(check));
		recursion(i);
	}
	cout << result;
	//system("Pause");
}