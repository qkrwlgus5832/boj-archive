#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>


using namespace std;

pair <int, int> recursion(int index, string s, int parentvalue) {
	int tmpvalue = 0;
	int value = 1;
	for (int i = index; i < s.size();) {
		if (s[i] >= '0' && s[i] <= '9') {
			tmpvalue++;
			value = s[i] - '0';
		}
		else if (s[i] == '(') {
			tmpvalue--;
			pair <int, int> result =recursion(i + 1, s, value);
			tmpvalue += result.first;
			i = result.second;
			continue;
		}
		else if (s[i] == ')') {
			return{ parentvalue * tmpvalue, i + 1 };
		}
		i++;
	}
	return{ tmpvalue , s.size() };
}

int main() {
	string input;
	cin >> input;
	cout << recursion(0,input, 0).first;
	//system("Pause");
}