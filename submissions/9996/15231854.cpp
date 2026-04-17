#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> v;


bool findMatchingPattern(string patternleftword, string patternrightword
	, string word) {
	if ((int)word.find(patternleftword) == 0) {
		auto pos = word.rfind(patternrightword);
		if (pos != string::npos && pos == word.length() - patternrightword.size()) {
			return true;
		}
	}
	return false;
}
int main() {
	int N;
	cin >> N;
	string input;

	cin >> input;

	string tmp;
	int pos = (int)input.find('*');


	string word1 = input.substr(0, pos);
	string word2 = input.substr(pos + 1, input.length());


	for (int i = 0; i < N; i++) {
		cin >> tmp;

		if (findMatchingPattern(word1, word2, tmp) == true)
			printf("DA\n");
		else
			printf("NE\n");

	}

	//system("Pause");
}