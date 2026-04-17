#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int check[2001][2001];

int main() {
	int N;
	cin >> N;

	vector <int> v;
	v.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}


	for (int i = 0; i < N; i++) {
		map <int, int> m;
		int count = 0;

		for (int j = i; j < N; j++) {
			m[v[j]]++;
			if (m[v[j]] % 2 != 0) {
				count++;
			}
			else {
				count--;
			}

			if ((j - i) % 2 == 0) {
				if (count == 1) {
					check[i + 1][j + 1] = 1;
				}
			}
			else {
				if (count == 0) {
					check[i + 1][j + 1] = 1;
				}
			}
		}


	}
	int M;

	int S, E;
	cin >> M;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &S, &E);
		printf("%d\n", check[S][E]);
	}
	//system("Pause");
}
