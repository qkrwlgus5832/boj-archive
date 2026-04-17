#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

multiset <int> s;


int main() {
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	cin >> T;
	for (int i = 0; i < T; i++) {
		int k;
		cin >> k;
		char c; char dd;
		int value;
        s.clear();
		for (int j = 0; j < k; j++) {
			cin >> c >> value;
			if (c == 'I') {
				s.insert(value);
			}
			else if (c == 'D') {
				if (s.size() == 0)
					continue;
				if (value == -1) {
					auto iter = s.begin();
					s.erase(iter);
				}
				else if (value == 1) {
					auto iter = --s.end();
					s.erase(iter);
				}
			}
		}
		if (s.size() == 0) {
			cout << "EMPTY" << endl;
			continue;
		}
		int maxvalue = INT_MIN;
		int minvalue = INT_MAX;
		for (auto iter = s.begin(); iter != s.end(); iter++) {
			minvalue = min(minvalue, *iter);
			maxvalue = max(maxvalue, *iter);
		}
		cout << maxvalue << " " << minvalue << endl;
	}
	//system("Pause");
}
