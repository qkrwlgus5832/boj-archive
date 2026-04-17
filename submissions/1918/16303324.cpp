#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;

stack <char> operator_;
string result = "";
void changenotation() {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			operator_.push(s[i]);
		}
		else if (s[i] == '*' || s[i] == '/') {
			while (operator_.size()) {
				if (operator_.top() == '*' || operator_.top() == '/') {
					result += operator_.top();
					operator_.pop();
				}
				else
					break;
			}
			operator_.push(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-') {
			while (operator_.size()) {
				if (operator_.top() != '(') {
					result += operator_.top();
					operator_.pop();
				}
				else
					break;
			}
			operator_.push(s[i]);
		}
		else if (s[i] == ')') {
			while (operator_.size()) {
				if (operator_.top() != '(') {
					result += operator_.top();
					operator_.pop();
				}
				else {
					operator_.pop();
					break;
				}
			}
		}
		else {
			result += s[i];
		}
	}
	while (operator_.size()) {
		result += operator_.top();
		operator_.pop();
	}
}
int main() {
	
	cin >> s;
	changenotation();
	cout << result;
	//system("Pause");
}