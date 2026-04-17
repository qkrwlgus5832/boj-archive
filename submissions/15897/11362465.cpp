#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int n;
unsigned long long result = 0;

int main() {
	cin >> n;



	for (int i = 1; i <= n; i++) {
		 if ((n - 1) / i == 0)
			result += 1;
		else 
			result += (n - 1) / i + 1;
	

	}
	cout << result;

}