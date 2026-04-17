#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int T;
string P;
int n;
char P1[30000001];
deque <int> q;
stack <int> st;
vector <int> v;
void AC() {
	int sizeR = 0;
	for (int i = 0; i < P.size(); i++) {
		if (P.at(i) == 'R') {
			sizeR = sizeR + 1;
		}

		else if (P.at(i) == 'D') {
			if (q.empty() == 1) {
				cout << "error" << endl;
				return;
			}
			else
				if (sizeR % 2 == 0)
					q.pop_front();
				else
					q.pop_back();

		}

	}


	if (sizeR % 2 == 1) {
		while (!q.empty()) {
			st.push(q.front());
			q.pop_front();
		}
		while (!st.empty()) {
			q.push_back(st.top());
			st.pop();
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
		scanf("%s", P1);

		char seps[] = "[,]";
		char *token = strtok(P1, seps);

		while (token != NULL) {
			q.push_back(atoi(token));
			token = strtok(NULL, seps);
		
			
		}

	

		AC();

	}


}