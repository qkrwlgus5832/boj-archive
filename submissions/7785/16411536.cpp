#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <string>
#include <string.h>
#include <functional>
using namespace std;

int n;
set <string> s;

int main() {
	cin >> n;
	char input[6];
	char access[6];
	string personname;
	for (int i = 0; i < n; i++) {
		scanf("%s", input);
		personname = input;
		scanf("%s", access);
		if (access[4] == 'r')
			s.insert(personname);
		else if (access[4] == 'e')
			s.erase(personname);
	}

	for (auto riter = s.rbegin(); riter != s.rend(); riter++) {
		printf("%s\n", (*riter).c_str());
	}
	system("Pause");
}