#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	getline(cin, s);

	string result = "";

	for (char ch : s) {
		if (ch >= 'a' && ch <= 'z') {
			if (ch + 13 > 'z') {
				result += ('a' - 1) + (ch + 13 - 'z');
			}
			else {
				result += (ch + 13);
			}
		}
		else if (ch >= 'A' && ch <= 'Z') {
			if (ch + 13 > 'Z') {
				result += ('A' - 1) + (ch + 13 - 'Z');
			}
			else {
				result += (ch + 13);
			}
		}
		else {
			result += ch;
		}
	}
	cout << result;
//	system("Pause");
}