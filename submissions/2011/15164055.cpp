#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>

using namespace std;

string input;

int BFS(int index, string tmpstring) {
	queue <pair <int, string>> q;
	int count = 0;
	q.push(make_pair(0, tmpstring));

	while (!q.empty()) {
		int frontindex = q.front().first;
		string fronttmpstring = q.front().second;
		q.pop();
		if (frontindex >= input.size()) {
			count++;
			continue;
		}
		else if (input[frontindex] == '0') {
			continue;
		}

		if ((input[frontindex] - '0') * 10 + (input[frontindex] - '0') <= 26) {
			int dd = (input[frontindex] - '0') * 10 + (input[frontindex + 1] - '0');
			q.push(make_pair(frontindex + 2, fronttmpstring + char ('A' + dd - 1)));
		}

		q.push(make_pair(frontindex + 1, fronttmpstring + char('A' + input[frontindex] - '0' - 1)));
	}

	return count;

}

int main() {
	cin >> input;
	cout << BFS(0, "");
	//system("Pause");
}