#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;


int N, M;
int N2[10];
char N1[10][10];
string v;
 char tmp = ' ';
void recursion(int i1, int i2) {

	if (i1== M) {
		const char *s = v.c_str();
		printf("%s\n", s);
		v.pop_back();
		int dd = v.rfind(" ");
		if (dd == -1) {
			v.clear();
		}
		else {
			v.erase(dd+1, v.size() - (dd + 1));
		}

		return;
	}

	for (int i = i2; i < N; i++) {
		string tmp1 = N1[i];
		v = v + tmp1;
		v.push_back(tmp);
		recursion(i1+1, i);
	}
	if (v.size() >= 2) {
		v.pop_back();
		int dd = v.rfind(" ");
		if (dd == -1) {
			v.clear();
		}
		else {
			v.erase(dd+1, v.size() - (dd + 1));
		}

	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		scanf("%d", &N2[i]);

	sort(N2, N2+N);

	for (int i = 0; i < N; i++) {
		 _itoa(N2[i], N1[i], 10);
	}

	recursion(0, 0);

}