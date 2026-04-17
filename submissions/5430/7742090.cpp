#define _CRT_SECURE_NO_WARNINGS
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
			while(!q.empty()){
				st.push(q.front());
				q.pop_front();

			}
			while (!st.empty()) {
				q.push_back(st.top());
				st.pop();

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
		if (q.size()==1)
		cout << q.front();
		else
			cout << q.front() << ",";
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