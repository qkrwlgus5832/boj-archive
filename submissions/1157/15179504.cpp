#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string input;

vector <pair <char,int>> v;

bool compare(pair <int, int> a, pair <int, int> b) {
	return a.second > b.second;
}

int main() {
	cin >> input;

	v.resize(30);


	for (int i = 0; i < input.size(); i++) {
		if ('a' <= input[i] && input[i] <= 'z') {
			v[input[i] - 'a'].first = input[i] - 'a';
			v[input[i] - 'a'].second++;
		}
		else if ('A' <= input[i] && input[i] <= 'Z') {
			v[input[i] - 'A'].first = input[i] - 'A';
			v[input[i] - 'A'].second++;
		}
	}

	sort(v.begin(), v.end(), compare);

	if (v[0].second == v[1].second)
		cout << "?";
	else
		printf("%c", 'A' + v[0].first);

	//system("Pause");
}