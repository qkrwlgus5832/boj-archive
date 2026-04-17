#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string S;
vector <string> inputstring;
int N;
bool result = false;
map <string, bool> m;


void recursion(string S) {
	if (result == true)
		return;
	if (S.size() == 0) {
		result = true;
		return;
	}
	for (int i = 0; i < N; i++) {
		 if (inputstring[i].size() > S.size())
			continue;
		else if (inputstring[i] == S.substr(0, inputstring[i].size())) {
			if (m[S.substr(inputstring[i].size())] == false) {
				m[S.substr(inputstring[i].size())] = true;
				recursion(S.substr(inputstring[i].size()));
			}
		}
	}

}

int main() {
	cin >> S;
	cin >> N;

	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		inputstring.push_back(tmp);
	}
	m[S] = true;
	recursion(S);
	cout << result;
	//system("Pause");
}