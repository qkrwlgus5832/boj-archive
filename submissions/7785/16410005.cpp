#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <vector>

using namespace std;

map <string, bool> m;
priority_queue <string, vector <string> ,less <string>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string input;
	string access;

	for (int i = 0; i < n ; i++) {
		cin >> input;
		cin >> access;
		if (access[access.size() - 1] == 'r') {
			m[input] = true;
		}
		else if (access[access.size() - 1] == 'e') {
			m.erase(input);
		}
	} 

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		q.push(iter->first);
	}
	while (q.size()){
		cout << q.top() << endl;
		q.pop();
	}
	//system("Pause");
}