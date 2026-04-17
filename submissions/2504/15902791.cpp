#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include <iostream>
#include <string>

using namespace std;


string input;

stack <char> s;
bool check[31];

bool flag = false;

char getopposite(char tmp) {
	if (tmp == '(')
		return ')';
	else if (tmp == '[')
		return ']';
}

int recursion(int index) {
	stack <char> s;
	int count = 0;
	int tmpcount = 0;

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
			}

		}
		else if (input[i] == ')' && s.size() && s.top() == '(') {
			if (tmpcount == 0)
				count += 2;
			else
				count += tmpcount * 2;
			s.pop();

		}
		else if (input[i] == ']' && s.size() && s.top() == '[') {
			if (count == 0)
				count += 3;
			else
				count += tmpcount * 3;
			s.pop();
		}
		else if (index != 0)
			return count;
		else
			return 0;

		check[i] = true;
	}
	if (s.size() == 0)
		return count;
	else {
		flag = true;
		return 0;
	}
	

}

int main() {
	
	cin >> input;

	if (flag == true)
		cout << 0;
	else
		cout << recursion(0);
	//system("Pause");
	
}