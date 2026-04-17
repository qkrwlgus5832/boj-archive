#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int main() {
	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int result = INT_MAX;

	result = min(result, abs(x));
	result = min(result, abs(y));
	result = min(result, abs(w-x));

	result = min(result, abs(h - y));

	cout << result;

}