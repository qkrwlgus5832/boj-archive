#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int T;

deque <char> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	string input;

	for (int i = 0; i < T; i++) {
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			if (input[j] == '(') {
				st.push_back('(');
			}
			else if (input[j] == ')') {
				if (st.size() >=1 && st.back() == '(')
					st.pop_back();
				else {
					st.push_back(')');
					break;
				}
			}
		}
		if (st.size() == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		st.clear();
	}
	//system("Pause");
}