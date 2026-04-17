#define _CRT_SECURE_NO_WARNINGS
#include <iostream>	
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;


int N;

vector <int> v[100001];
int check[100001];
bool flag = false;


void BFS(int i) {
	check[i] = true;
	queue <int> q;
	q.push(i);

	while (!q.empty()) {
		int fronti = q.front();
		q.pop();
		for (int i1 = 0; i1 < v[fronti].size(); i1++) {
			if (check[v[fronti][i1]] == false) {
				check[v[fronti][i1]] = fronti;
				q.push(v[fronti][i1]);
			}
		}
	}

}

int main() {
	cin >> N;
	int a, b;

	cout.tie(NULL);

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	BFS(1);

	for (int i = 2; i <= N; i++) {
		//memset(check, false, sizeof(check));
		cout << check[i] << endl;
	}

	//system("Pause");
}