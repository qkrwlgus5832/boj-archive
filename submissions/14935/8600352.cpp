#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;
string x;


vector <int> v;
vector <int> v1;


int FA(string x1) {

	int a = x.at(0) - '0';
	int a1= x1.size();

	return a*a1;

}



int main() {
	cin >> x;
	

	
	
	
	int count = 0;
	int f = 0;




	while (1) {
		int tmp = FA(x);
		if (tmp == atoi(x.c_str())) {
			f = 1;
			break;

		}

		else {
			string a = to_string(tmp);
			x = a;

		}
	}
	
	if (f == 1)
		cout << "FA";
	else
		cout << "NFA";




}