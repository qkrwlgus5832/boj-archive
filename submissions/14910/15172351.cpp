#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int N;
vector <int> v;
int main() {
	int tmp;

	int lasttmp = INT_MIN;

	bool flag = false;
	while (scanf("%d", &tmp) != EOF) {
		if (tmp < lasttmp)
			flag = true;
		lasttmp = tmp;
	}
	if (flag == true)
		cout << "Bad";
	else
		cout << "Good";
	//system("Pause");
}