#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

vector <char> input;

long long minvalue = LLONG_MAX;
long long maxvalue = 0;
bool check[11];
int k;

void recursion(int index, long long value, int lastdigit) {
	if (index == k) {
		minvalue = min(value, minvalue);
		maxvalue = max(value, maxvalue);
		return;
	}
	if (index == -1) {
		for (int i = 0; i < 10; i++) {
			check[i] = true;
			recursion(index+ 1, i , i);
			check[i] = false;
		}
	}
	else if (input[index] == '<') {
		for (int i = lastdigit + 1; i < 10; i++) {
			if (check[i] == false) {
				check[i] = true;
				recursion(index + 1, (long long) value * 10 + i, i);
				check[i] = false;
			}
		}
	}
	else if (input[index] == '>') {
		for (int i = 0; i < lastdigit; i++) {
			if (check[i] == false) {
				check[i] = true;
				recursion(index + 1, (long long) value * 10 + i, i);
				check[i] = false;
			}
		}
	}
}
int main() {

	cin >> k;
	char tmp;
	for (int i = 0; i < k; i++) {
		cin >> tmp;
		input.push_back(tmp);
	}

	recursion( -1 , 0, 0);

	cout.width(k+1);
	cout.fill('0');

	
	cout << maxvalue << endl;
	cout.width(k+1);
	cout.fill('0');
	cout << minvalue;

	//system("Pause");
}