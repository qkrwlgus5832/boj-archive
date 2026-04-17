#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>

using namespace std;


deque <int> getdivde(int x) {
	deque <int> q;
	int d1 = x / 1000;
	int d2 = (x % 1000) / 100;
	int d3 = (x % 1000) % 100 / 10;
	int d4 = (x % 1000) % 100 % 10;
	q.push_back(d1);
	q.push_back(d2);
	q.push_back(d3);
	q.push_back(d4);
	return q;
}

int getcaculate(deque <int>& q) {
	int d1 = q[0];
	int d2 = q[1];
	int d3 = q[2];
	int d4 = q[3];
	return ((d1 * 10 + d2) * 10 + d3) * 10 + d4;
}

int D(int x) {
	return 2 * x % 10000;
}

int S(int x) {
	if (x - 1 == 0)
		return 9999;
	else
		return x - 1;
}

int L(int x) {
	deque <int> tmp = getdivde(x);
	int dd = tmp.front();
	tmp.pop_front();
	tmp.push_back(dd);
	return getcaculate(tmp);
}

int R(int x) {
	deque <int> tmp = getdivde(x);
	int dd = tmp.back();
	tmp.pop_back();
	tmp.push_front(dd);
	return getcaculate(tmp);
}

int checkdd(int dd) {
	if (dd == 0) {
		return 9999;
	}
	else
		return dd;
}
void DFS(int A, int B) {
	queue <pair<int, vector<char>>> q;
	bool check[10000] = { false, };
	vector <char> v;
	q.push(make_pair(A, v));
	check[A] = true;
	int level = 0;
	while (!q.empty()) {
		for (int i = 0; i < q.size(); i++) {
			int front = q.front().first;
			vector <char> frontvector = q.front().second;
			if (front == B) {
				for (int i = 0; i < frontvector.size(); i++)
					printf("%c", frontvector[i]);
				return;
			}

			q.pop();
			int dd = D(front);
			dd = checkdd(dd);

			if (check[dd] == false) {
				frontvector.push_back('D');
				q.push(make_pair(dd, frontvector));
				check[dd] = true;
				frontvector.pop_back();
			}
		
			dd = S(front);
			dd = checkdd(dd);

			if (check[dd] == false) {
				frontvector.push_back('S');
				q.push(make_pair(dd, frontvector));
				check[dd] = true;
				frontvector.pop_back();
			}
		
			dd = L(front);
			dd = checkdd(dd);

			if (check[dd] == false) {
				frontvector.push_back('L');
				q.push(make_pair(dd, frontvector));
				check[dd] = true;
				frontvector.pop_back();
			}
	
			dd = R(front);
			dd = checkdd(dd);

			if (check[dd] == false) {
				frontvector.push_back('R');
				q.push(make_pair(dd, frontvector));
				check[dd] = true;
				frontvector.pop_back();
			}
		}
		level++;
	}

}

int main() {
	int T;
	int A, B;
	cin >> T;

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &A, &B);
		DFS(A, B);
		printf("\n");
	}

	//system("Pause");
}