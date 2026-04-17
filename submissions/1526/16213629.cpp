#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;

int recursion(int value) {
	if (value > N)
		return false;
	int ifAnswer1 = recursion(value * 10 + 4);
	if (ifAnswer1 == false)
		return value;
	int ifAnswer2 = recursion(value * 10 + 7);
	if (ifAnswer2 == false)
		return ifAnswer1;
	if (ifAnswer1 < ifAnswer2)
		return ifAnswer2;
	else
		return ifAnswer1;
}


int main() {
	cin >> N;
	cout << recursion(0);
	//system("Pause");
}