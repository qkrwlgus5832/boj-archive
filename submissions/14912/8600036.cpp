#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>


using namespace std;
int n;
string d;


int main() {
	cin >> n >> d;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		

		string a = to_string(i);

		for (int i1 = 0; i1 < a.size(); i1++) {
			if (a.at(i1) == d.at(0)) {
				count = count + 1;

			}
		}


	}
	cout << count;

}