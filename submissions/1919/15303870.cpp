#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int beforewordarray[27];
int afterwordarray[27];

int main() {
	string beforeword;
	string afterword;
	cin >> beforeword;
	cin >> afterword;

	for (int i = 0; i < beforeword.size(); i++) {
		beforewordarray[beforeword[i] - 'a']++;
	}
	for (int i = 0; i < afterword.size(); i++) {
		afterwordarray[afterword[i] - 'a']++;
	}

	int result = 0;
	for (int i = 0; i < 27; i++) {
		int maxvalue = max(beforewordarray[i], afterwordarray[i]);
		int minvalue = min(beforewordarray[i], afterwordarray[i]);
		result += maxvalue - minvalue;
	}
	cout << result;
	//system("Pause");
}