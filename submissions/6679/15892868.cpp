#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int getjinsu(int x, int jinsu) {
	int count = 0;
	while (1) {
		count += x % jinsu;
		x = x / jinsu;
		if (x == 0)
			break;
	}
	return count;
}


bool singi(int x) {
	if (getjinsu(x, 10) == getjinsu(x, 12) && getjinsu(x, 10) == getjinsu(x, 16)) {
		return true;
	}
	return false;
}
int main() {
	for (int i = 1000; i <= 9999; i++) {
		if (singi(i) == true)
			printf("%d\n", i);
	}
	//system("Pause");
}