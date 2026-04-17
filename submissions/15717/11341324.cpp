#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;



long long binary_search(long long x, long long y) {
	if (y - x <= 1) {
		long long cc = 1;
		cc = cc * (long long) pow(2, (y-x));
		return cc;
	}
	if ((y - x) % 2 == 0) {
		long long cc = binary_search(x, (x + y) / 2);

		return cc * cc % ((long long)pow(10, 9) + 7);
	}
	else {
		long long cc = binary_search(x, (x + y) / 2);

		return (cc * cc * 2) % ((long long)pow(10, 9) + 7);
	}

}
int main() {
	unsigned long long N;
	cin >> N;
	
	if (N == 0) {
		cout << 0;
		return 0;
		
	}

	

	unsigned long long result = binary_search(0, N - 1);
	
	
	
	cout << result;

	
}