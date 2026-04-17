#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;



long long binary_search(long long A, long long x, long long y, long long C) {
	if (y - x <= 1) {
		long long cc = 1;
		cc = cc * (long long)pow(A, (y - x)) % C;
		return cc;
	}
	if ((y - x) % 2 == 0) {
		long long cc = binary_search(A, x, (y - x) / 2, C);

		return cc * cc % C;
	}
	else {
		long long cc = binary_search(A, x, (y - x) / 2, C);
		long long cc2 = (cc * A) % C;
		return (cc * cc2) % C;
	}

}
int main() {


	long long A, B, C;
	cin >> A >> B >> C;

	

	cout<<  binary_search(A,0, B, C);
	
	
	
	

	
}