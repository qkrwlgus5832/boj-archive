#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, K;

bool check[26];
vector <string> input;
int result = 0;
void recursion(int index, int teachedcount, int aimcount) {
	if (aimcount == teachedcount) {
		int count = N;
		for (int i = 0; i < input.size(); i++) {
			for (int j = 0; j < input[i].size(); j++) {
				if (check[input[i][j] - 'a'] == false) {
					count--; break;
				}
			}
		}
		result = max(result, count);
		return;
	}
	for (int i = index; i < 26; i++) {
		if (check[i] == false) {
			check[i] = true;
			recursion(i + 1, teachedcount + 1, aimcount);
			check[i] = false;
		}
	}
}

void charcheck(char c) {
	check[c - 'a'] = true;
}
int main() {
	cin >> N >> K;
	
	string word;
	for (int i = 0; i < N; i++) {
		cin >> word;
		input.push_back(word);
	}
	charcheck('a');
	charcheck('n');
	charcheck('t');
	charcheck('i');
	charcheck('c');
	if (K < 5)
		cout << 0;
	else {
		recursion(0, 0, K - 5);
		cout << result;
	}

	//system("Pause");
}