#define _CRT_SECURE_NO_WRANINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;


vector <int> v1[401];
vector <int> v2[401];

bool check1[401][401];

bool check2[401][401];



bool* BFS1(int i, vector <int> v[401]) {
	queue <int> q;
	bool check[401] = { false, };
	check[i] = true;

	q.push(i);

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i1 = 0; i1 < v[front].size(); i1++) {
			if (check[v[front][i1]] == false) {
				check1[front][v[front][i1]] = true;
				check[v[front][i1]] = true;
				q.push(v[front][i1]);
			}
		}
	}
	return check;
}

bool* BFS2(int i, vector <int> v[401]) {
	queue <int> q;
	bool check[401] = { false, };
	check[i] = true;

	q.push(i);

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i1 = 0; i1 < v[front].size(); i1++) {
			if (check[v[front][i1]] == false) {
				check[v[front][i1]] = true;
				check2[front][v[front][i1]] = true;
				q.push(v[front][i1]);
			}
		}
	}
	return check;
}

int main() {
	int n, k;
	cin >> n >> k;
	int a, b;

	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		check1[a][b] = true;
		check2[b][a] = true;
	}
	
	for (int i = 1; i <= n; i++) {
		BFS1(i, v1);
		BFS2(i, v2);
	}

	int s;
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> a >> b;
		bool check[401] = { false, };
		//BFS(a, v1, check);
		if (check1[a][b] == true) {
			printf("-1\n");
			continue;
		}
		//BFS(a, v2, check);
		if (check2[a][b] == true) {
			printf("1\n");
			continue;
		}
		else
			printf("0\n");
	}
	//system("Pause");
}
