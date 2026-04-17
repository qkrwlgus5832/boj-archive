#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include <iostream>
#include <string>

using namespace std;


string input;

bool check[31];

bool flag = false;

stack<char> s2;

int recursion(int index) {
	int count = 0;
	int tmpcount = 0;

	stack <char> s;

	for (int i = index; i < input.size(); i++) {
		if (check[i] == true) {
			continue;
		}

		if (input[i] == '(' || input[i] == '[') {
			if (s.size() >= 1) {
				tmpcount = recursion(i);
			}
			else {
				s.push(input[i]);
				s2.push(input[i]);
			}

		}
		else if (input[i] == ')' && s.size() && s.top() == '(') {
			if (tmpcount == 0)
				count += 2;
			else
				count += tmpcount * 2;
			s.pop();
			s2.pop();
			tmpcount = 0;

		}
		else if (input[i] == ']' && s.size() && s.top() == '[') {
			if (tmpcount == 0)
				count += 3;
			else
				count += tmpcount * 3;
			s.pop();
			s2.pop();
			tmpcount = 0;
		}
		else if (input[i] == ']' && !(s2.size() && s2.top() == '[')) {
			flag = true;
			return 0;
		}

		else if (input[i] == ')' && !(s2.size() && s2.top() == '(')) {
			flag = true;
			return 0;
		}

		else {
			return count;
		}
		check[i] = true;
	}

	if (s.size() == 0 && s2.size() == 0)
		return count;
	else {
		flag = true;
		return 0;
	}
}

int main() {

	cin >> input;


	int result = recursion(0);
	if (flag == true) {
		cout << 0;
	}
	else {
		cout << result;
	}
	//system("Pause");

}