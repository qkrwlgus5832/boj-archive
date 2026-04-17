#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int N;
int main() {
	cin >> N;

	int tmp = 1;
	int size = 1;
	int nsize = 0;
	while (1) {
		if (tmp == pow(10, size))
			size++;

		if (nsize + size > N)
			break;


		nsize = nsize + size;
		tmp++;
	}

	if (nsize == N) {
		tmp = tmp - 1;
	}
	string s = to_string(tmp);
	
	if (nsize == N) {
		cout << s.at(s.size() - 1);
	}

	else {
		cout << s.at(N - nsize - 1);
	}




}