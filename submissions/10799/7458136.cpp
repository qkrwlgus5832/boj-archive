#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;
char s[100001];
stack <char> st;
int pipe() {
	int count = 0;
	int count2 = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '(')
			count2 = count2 + 1;
		else if (s[i - 1] == '(') {
			count2 = count2 - 1;
			count = count + count2;
		}
		else {
			count2 = count2 - 1;
			count = count + 1;
		}
	}

	return count;
}

int main() {
	cin >> s;

	cout << pipe() << endl;


}