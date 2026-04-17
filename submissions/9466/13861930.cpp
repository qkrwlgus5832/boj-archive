#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int v[100001];

bool check[100001];

int cyclecheck[100001];

bool finished[100001];


void finishset(vector <int> &ve) {
	for (int i = 0; i < ve.size(); i++) {
		finished[ve[i]] = true;
	}
}

int BFS(int i) {
	vector <int> ve;
	queue <int> q;
	q.push(i);
	int count = 1;
	cyclecheck[i] = count;
	ve.push_back(i);
	check[i] = true;

	while (!q.empty()) {
		int fronti = q.front();
		q.pop();

		if (finished[v[fronti]] == true)
			break;

		if (cyclecheck[v[fronti]] == 0 && check[v[fronti]] == false) {
			cyclecheck[v[fronti]] = ++count;
			q.push(v[fronti]);
			ve.push_back(v[fronti]);
			check[v[fronti]] = true;
		}
		else if (cyclecheck[v[fronti]] != 0 && check[v[fronti]] == true) {
			finishset(ve);
			return count - (cyclecheck[v[fronti]] - 1);
		}
	
	}
	//finishset(ve);

	return 0;
}


int main() {
	int T;
	int n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		int tmp;
		memset(v, 0, sizeof(v));
		for (int j = 1; j <= n; j++) {
			scanf("%d", &tmp);
			v[j] = tmp;
		}
		memset(check, false, sizeof(check));
		memset(finished, false, sizeof(finished));
		memset(cyclecheck, 0, sizeof(cyclecheck));
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