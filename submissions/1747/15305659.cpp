#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;


bool issosu(int x) {
	for (int i = 2; i <= x / 2; i++) {
		if (x% i == 0) {
			return false;
		}
	}
	return true;
}

int change(int x) {
	string s = to_string(x);
	int sum = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		sum = sum * 10 + (s[i]- '0');
	}
	return sum;
}

int main() {
	int N;
	cin >> N;
	string s = to_string(N);

	int size = s.size();
	
	int jaritsu;

	if (size % 2 == 0) {
		jaritsu = size / 2;
	}
	else if (size % 2 == 1) {
		jaritsu = size / 2 + 1;
	}

	int sum = 0;
	for (int i = 0; i < jaritsu; i++) {
		sum = sum * 10 + (s[i] - '0');
	}

	while (1) {
		int tmp;
		bool flag = false;
		for (int i = sum; i < pow(10, jaritsu); i++) {
			if (size % 2 == 0) {
				tmp = change(i);

			}
			else if (size % 2 == 1) {
				tmp = change(i / 10);

			}

			int parindrum = i * pow(10, size - jaritsu) + tmp;
			if (parindrum < N)
				continue;
			if (issosu(i * pow(10, size - jaritsu) + tmp) == true) {
				cout << parindrum;
				flag = true;
				break;
			}

		}
		if (flag == true)
			break;
		size++;
		if (size % 2 == 0) {
			jaritsu = size / 2;
		}
		else if (size % 2 == 1) {
			jaritsu = size / 2 + 1;
		}
		sum = pow(10, jaritsu - 1);

	}
	//system("Pause");
}