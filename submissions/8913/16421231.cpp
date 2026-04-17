#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <string>
#include <stack>

using namespace std;

bool stringPop(string inputstring) {
	stack <char> st;
	for (int i = 0; i < inputstring.size(); i++) {
		if (i == inputstring.size() -1 || inputstring[i] != inputstring[i + 1]) {
			bool flag = false;
			while (!st.empty() && inputstring[i] == st.top()) {
				st.pop();
				flag = true;
			}
			if (flag == false)
				st.push(inputstring[i]);
		}
		else {
			st.push(inputstring[i]);
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
		printf("%d", stringPop(input));
	}
	//system("Pause");

}