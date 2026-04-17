#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;


string input;

stack <char> s;

vector <char> q;

vector <char> tmpvector;

bool stringbomb(string bombstring) {
	int index = 0;
	int size = s.size();
	bool flag = false;
	while(!s.empty()) {
		char front = s.top();
		if (front == bombstring[index]) {
			index++;
			tmpvector.push_back(front);
			if (index == bombstring.size()) {
				index = 0;
				flag = true;
				tmpvector.clear();
			}
		}
		else if (tmpvector.size() >= 1) {
			q.insert(q.end(), tmpvector.begin(), tmpvector.end());
		/*	for (int i = 0; i < tmpvector.size(); i++) {
				q.push_back(tmpvector[i]);
			}*/
			tmpvector.clear();
			index = 0;
			continue;
		}
		else {
			q.push_back(front);
			index = 0;
		}
	
		s.pop();
	}
	return flag;
}

void stackpush() {
	int size = q.size();
	for (int i = 0; i < size; i++) {
		s.push(q.back());
		q.pop_back();
	}
}

int main() {
	cin >> input;
	for (int i = input.size() -1; i >=0; i--) {
		s.push(input[i]);
	}
	string bombstring;
	cin >> bombstring;


	while (1) {
		bool flag = stringbomb(bombstring);
		if (flag == false) {
			break;
		}
		stackpush();
	}

	int size = q.size();
	if (size == 0) {
		cout << "FRULA";
	}
	else {
		for (int i = 0; i < size; i++) {
			printf("%c", q[i]);
		}
	}
	//system("Pause");
}