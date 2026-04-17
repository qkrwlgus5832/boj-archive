#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int jimin;
int hansu;

int number(int x) {
	if (x % 2 == 1)
		return (x + 1) / 2;
	else
		return x / 2;
}
int main() {
	int round = 1;

	cin >> N >> jimin >> hansu;
	while (1) {
		int tmin = min(jimin, hansu);
		int tmax = max(jimin, hansu);

		if (tmin % 2 == 1 && tmin + 1 == tmax) {
			break;
		}
		jimin = number(jimin);
		hansu = number(hansu);
		round++;
	}

	cout << round;
}