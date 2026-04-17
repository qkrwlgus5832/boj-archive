#define _CRT_SECURE_NO_WRANINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;


vector <int> v1[401];
vector <int> v2[401];

bool* BFS(int i, vector <int> v[101], bool check[101]) {
	queue <int> q;
	check[i] = true;

	q.push(i);

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i1 = 0; i1 < v[front].size(); i1++) {
			if (check[v[front][i1]] == false) {
				check[v[front][i1]] = true;
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
		v1[a].push_back(b);
		v2[b].push_back(a);
	}
	
	int s;
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> a >> b;
		bool check[401] = { false, };
		BFS(a, v1, check);
		if (check[b] == true) {
			printf("-1\n");
			continue;
		}
		BFS(a, v2, check);
		if (check[b] == true) {
			printf("1\n");
			continue;
		}
		else
			printf("0\n");
	}
	//system("Pause");
}
