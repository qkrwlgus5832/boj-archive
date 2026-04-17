#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>

using namespace std;

int N;

int cow[11];

int main() {
	cin >> N;

	memset(cow, -1, sizeof(cow));

	int cownumber;
	int location;
	int result = 0;
	for (int i = 0; i < N; i++) {
		cin >> cownumber >> location;
		if (cow[cownumber] != -1 && cow[cownumber] != location) {
			result++;
			
		}
		cow[cownumber] = location;

	}
	cout << result;
	//system("Pause");
}