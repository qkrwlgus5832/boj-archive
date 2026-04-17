#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>

using namespace std;


int lgetdivde(int x) {
	deque <int> q;
	int d1 = x / 1000;
	int d2 = (x % 1000) / 100;
	int d3 = (x % 1000) % 100 / 10;
	int d4 = (x % 1000) % 100 % 10;
	return d2 * 1000 + d3 * 100 + d4 * 10 + d1;
}

int rgetdivde(int x) {
	deque <int> q;
	int d1 = x / 1000;
	int d2 = (x % 1000) / 100;
	int d3 = (x % 1000) % 100 / 10;
	int d4 = (x % 1000) % 100 % 10;
	return d4 * 1000 + d1 * 100 + d2 * 10 + d3;
}


int D(int x) {
	return (2 * x) % 10000;
}

int S(int x) {
	if (x - 1 == -1)
		return 9999;
	else
		return x - 1;
}

int L(int x) {
	return lgetdivde(x);
}

int R(int x) {
	return rgetdivde(x);
}

bool checkIfAnswer(int dd, int B, string frontvector) {
	if (dd == B) {
		for (int i = 0; i < frontvector.size(); i++)
			printf("%c", frontvector[i]);
		return true;
	}
	else
		return false;
}


string BFS(int A, int B) {
	queue <int> q;
	bool check[10000] = { false, };
	pair <int, char> checkcourse[10000] = { make_pair(-1, '0'), };
	string v = "";
	q.push(A);
	check[A] = true;
	int level = 1;

	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int front = q.front();
			
			q.pop();
			int dd = D(front);

			if (check[dd] == false) {
				q.push(dd);
				check[dd] = true;
				checkcourse[dd] = make_pair(front, 'D');
				if (dd == B) {
					int tmp = B;
					for (int i = 0; i < level; i++) {
						v.push_back(checkcourse[tmp].second);
						tmp = checkcourse[tmp].first;
					}
					return v;
				}
			}

			dd = S(front);

			if (check[dd] == false) {
				checkcourse[dd] = make_pair(front, 'S');

				q.push(dd);
				check[dd] = true;
				if (dd == B) {
					int tmp = B;
					for (int i = 0; i < level; i++) {
						v.push_back(checkcourse[tmp].second);
						tmp = checkcourse[tmp].first;
					}
					return v;
				}

			}

			dd = L(front);

			if (check[dd] == false) {
				checkcourse[dd] = make_pair(front, 'L');

				q.push(dd);
				check[dd] = true;
				if (dd == B) {
					int tmp = B;
					for (int i = 0; i < level; i++) {
						v.push_back(checkcourse[tmp].second);
						tmp = checkcourse[tmp].first;
					}
					return v;
				}

			}

			dd = R(front);
			

			if (check[dd] == false) {
				q.push(dd);
				check[dd] = true;
				checkcourse[dd] = make_pair(front, 'R');
				if (dd == B) {
					int tmp = B;
					for (int i = 0; i < level; i++) {
						v.push_back(checkcourse[tmp].second);
						tmp = checkcourse[tmp].first;
					}
					return v;
				}

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
		string output = BFS(A, B);
		for (int i = output.size() - 1; i >= 0; i--)
			printf("%c", output[i]);
		printf("\n");
		
	}

	//system("Pause");
}