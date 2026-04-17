#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N;


string b;
int main(){

	cin >> N;

	cin >> b;


	int count = -1;
	int f = 0;
	for (int i = 0; i < N; i++) {
		if (f == 1) {
			f = 0;
			continue;
		}
		if (b.at(i) == 'L') {
			f = 1;
			count++;
		}
	}

	if (count == -1)
		cout << N;
	else
		cout << N - count;

}