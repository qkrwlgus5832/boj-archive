#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;


string input;

deque <char> s;

vector <char> q;

vector <char> tmpvector;




int main() {
	cin >> input;

	string bombstring;
	cin >> bombstring;


	for (int i = 0; i < input.size(); i++) {
		s.push_back(input[i]);
		if (s.size() >= bombstring.size()) {
			bool flag = false;
			for (int j1 = 0; j1 < bombstring.size(); j1++) {
				if (s[s.size() - 1 - j1] != bombstring[bombstring.size() - 1 - j1]) {
					flag = true;
					break;
				}
			}
			if (flag == false) {
				for (int j1 = 0; j1 < bombstring.size(); j1++) {
					s.pop_back();
				}
			}

		}
	}

	int size = s.size();
	if (size == 0) {
		cout << "FRULA";
	}
	else {
		for (int i = 0; i < size; i++) {
			printf("%c", s[i]);
		}
	}
	//system("Pause");
}