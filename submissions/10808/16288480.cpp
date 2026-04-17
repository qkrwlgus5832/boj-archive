#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string S;
int alpha[26];

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		alpha[S[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << " ";
	}
	//system("Pause");
}