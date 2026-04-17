#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;
int graph[201][201];
int N;
int M;
int unionfind[201];
bool check[201][201];

int find(int x) {
	if (unionfind[x] < 0)
		return x;
	unionfind[x] = find(unionfind[x]);

	return unionfind[x];
}
void unionq(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	else if (a > b)
		unionfind[a] = b;
	else if (a < b)
		unionfind[b] = a;

}



int main() {
	cin >> N;
	cin >> M;
	memset(unionfind, -1, sizeof(unionfind));





	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= N; j++) {
			scanf("%d" ,&graph[i][j]);
			if (graph[i][j] == 1 && check[j][i] == false) {
				unionq(i, j);
				check[i][j] = true;
			}

		}
	}





	int prev;

	int tmp = -1;
	for (int i = 0; i < M; i++) {
		if (tmp == -1) {
			scanf("%d", &tmp);
			prev = tmp;
			continue;
		}
		scanf("%d", &tmp);
		if (find(tmp) != find(prev)) {
			cout << "NO" << endl;
			break;
		}
		prev = tmp;
	}
	cout << "YES" << endl;
}