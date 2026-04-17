#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

stack <char> s;

int T;


int bracket(char *cafe) {
	for (int i = 0; i < strlen(cafe); i++) {
		if (cafe[i] == '(')
 			s.push('(');
		else {
			if (s.empty() == true)
				return 0;
			else {
				char ch = s.top();
				if (ch == '(')
					s.pop();
				else
					return 0;
			}
		}
	}

	      
	if (s.empty() == true)
		return 1;
	else
		return 0;

}

int main() {

	cin >> T;
	char cafe[100];

	for (int i = 0; i < T; i++) {
		cin >> cafe;

		if (bracket(cafe) == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		while (s.empty() != 1)
			s.pop();


	}

}