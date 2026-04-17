#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check[2501];
int DP[2501];
bool check2[2501];

int result = 0;
int main() {
	string input;
	getline(cin, input);
	string word;
	getline(cin, word);
	auto pos = input.find(word);
	while ( pos != string::npos) {
		check[pos] = true;
		pos = input.find(word, pos + 1);
	}

	for (int i = 0; i < input.size(); i++) {
		if (i>0 && DP[i] == 0) {
			DP[i] = DP[i - 1];
			result = max(result, DP[i]);
		}
		if (check[i] == true) {
			if (i > 0)
				DP[i + word.size() - 1] = DP[i - 1] + 1;
			else
				DP[i + word.size() - 1] = 1;
			result = max(result, DP[i + word.size() - 1]);
		}
		
	
	}
	cout << result;
	//system("Pause");
}