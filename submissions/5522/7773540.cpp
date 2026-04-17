#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


int main() {
	int tmp;
	int result = 0;
	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		result = result + tmp;
	}



	cout << result;

}