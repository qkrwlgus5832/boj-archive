#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <string>
#include <stack>

using namespace std;

bool stringPop(string inputstring) {
	stack <char> st;
	for (int i = 0; i < inputstring.size(); i++) {
		if (st.empty() || st.top() != inputstring[i])
			st.push(inputstring[i]);
		else if (st.top() == inputstring[i]) {
			if (i + 1 < inputstring.size() && inputstring[i] == inputstring[i + 1]) {
				st.push(inputstring[i]);
			}
			else {
				while (!st.empty()) {
					if (st.top() == inputstring[i])
						st.pop();
					else
						break;
				}
			}
		}
	}
	if (st.size() == 0)
		return true;
	else
		return false;
}



int main() {
	int N;
	cin >> N;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		printf("%d\n", stringPop(input));
	}
	//system("Pause");

}