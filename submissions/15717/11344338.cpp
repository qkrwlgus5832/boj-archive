#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;



unsigned long long binary_search(long long x, long long y) {
	long long extra = 1;
	while (y) {
		if (y % 2 == 1) {
			extra = extra * x % ((long long)pow(10, 9) + 7);
		}
		x = x* x % ((long long)pow(10, 9) + 7);
		y = y / 2;


	}
	return extra;


}
int main() {
	unsigned long long N;
	cin >> N;
	
	if (N == 0) {
		cout << 1;
		return 0;
		
	}

	

	cout<<  binary_search(2, N - 1);
	

	
	

	
}