#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int T;
string P;
int n;
string P1;
deque <int> q;
stack <int> st;
vector <int> v;
void AC() {
	for (int i = 0; i < P.size(); i++) {
		if (P.at(i) == 'R') {
			int size2 = q.size();
			if(size2 % 2 == 0) {
				for (int i = 0; i < size2/ 2; i++) {
					swap(q[i], q[size2 - 1 -i ]);
				}
			}
			else {
				for (int i = 0; i < size2/ 2 - 1; i++) {
					swap(q[i], q[size2 - 1 - i]);
				}
			}
		}

		else if (P.at(i) == 'D') {
			if (q.empty() == 1) {
				cout << "error" << endl;
				return;
			}
			else
			q.pop_front();

		}
	}

	cout << "[";
	while (!q.empty()) {
		if (q.size() == 1)
			printf("%d", q.front());
		else
			printf("%d,", q.front());
		q.pop_front();
	}
	cout << "]" << endl;
}


int main() {
	cin >> T;



	for (int i = 0; i < T; i++) {
		cin >> P;
		cin >> n;
		cin >> P1;
		for (int i = 0; i < n; i++) {
			char a = P1.at(i * 2 + 1);
			q.push_back(a -'0');
		}

		AC();

	}


}