#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

map <char, pair <int, int>> m;
string querty[4];

void mappingChar(string row, int index) {
	for (int i = 0; i < row.size(); i++) {
		m[row[i]] = { index, i };
	}
	querty[index] = row;
}

int main() {
	mappingChar("`1234567890-=", 0);
	mappingChar("QWERTYUIOP[]\"", 1);
	mappingChar("ASDFGHJKL;'", 2);
	mappingChar("ZXCVBNM,./", 3);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;

	while (!cin.eof()) {
		getline(cin, input);
		for (char current : input) {
			if (current == ' ') {
				cout << current;
				continue;
			}
			pair <int, int> location = m[current];
			cout << querty[location.first][location.second - 1];
		}
		cout << '\n';
	}
	
	//system("Pause");
}
