#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;



int T;


char c[2] = { '0','\0' };
string keylogger(string tmp) {
	string result = "";
	int pos = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp.at(i) == '<') {
			if (pos > 0)
				pos--;
		}

		else if (tmp.at(i) == '>') {
			if (pos < result.size())
				pos++;
		}


		else if (tmp.at(i) == '-') {
			if (pos >= 1) {
				pos--;
				result.erase(pos, 1);
			
			}
		}


		else {
			
			c[0] = tmp.at(i);
			string str(c);
			
			result.insert(pos, str);
			pos++;
		}

	}



	return result;
}

int main(){
	cin >> T;



	string tmp;

	for (int i = 0; i < T; i++) {
		cin >> tmp;
		cout << keylogger(tmp) << endl;
	}
	

	
}