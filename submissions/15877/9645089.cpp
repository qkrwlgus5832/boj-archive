#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;


int a, b;
int main() {
	cin >> a >> b;


	int count = 0;
	if (a == 0 && b == 0)
		cout << "Bob";
	else {
	
		while (1) {
			if (a == 0 && b == 0)
				break;
			else if (a >= b) {
		
				if (a >= 3 && b >= 1) {
					a = a - 3;
					b = b - 1;
				}
				else
					a--;

			}
			else {
				if (b >= 3 && a>= 1) {
					b = b - 3;
					a = a - 1;
				}
				else
					b--;

			}
			
			count++;
		
		}
		if ((count - 1) % 2 == 0)
			cout << "Alice";
		else
			cout << "Bob";


	}
}