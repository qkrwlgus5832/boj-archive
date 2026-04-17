#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;


int T;

char c[2] = { '0','\0' };

void keylogger(string tmp) {
	
	list <string> lst;
	list <string>::iterator itr = lst.begin();
	int pos = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp.at(i) == '<') {
			if (pos > 0) {
				itr--;
				pos--;
			}
		}

		else if (tmp.at(i) == '>') {
			if (pos < lst.size()) {
				itr++;
				pos++;
			}
		}


		else if (tmp.at(i) == '-') {
			if (pos >= 1) {
				pos--;
				lst.erase(--itr);
			}
		}


		else {
			c[0] = tmp.at(i);
			string str(c);
			lst.insert(itr, str);
	
			pos++;
		}

	}

	string result = "";
	for ( itr = lst.begin(); itr != lst.end(); itr++) {
		result = result + *itr;

	}



	printf("%s", result.c_str());
}

int main(){
	cin >> T;



	string tmp;

	for (int i = 0; i < T; i++) {
		cin >> tmp;

		keylogger(tmp);


		printf("\n");
	}
	

	
}