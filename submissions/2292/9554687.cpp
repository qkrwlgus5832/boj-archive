#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;
int main() {









	cin >> N;
	




	int sum = 1;
	int tmp = 6;
	int count = 1;
		while (1) {
		if (N <= sum + tmp)
			break;

		count++;
		sum = sum + tmp;
		tmp = tmp + 6;

	}

	if (N == 1)
		cout << 1;
	else
		cout << count+1;



}