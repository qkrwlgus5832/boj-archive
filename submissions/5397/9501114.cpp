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
	
	list <char> lst;
	list <char>::iterator itr;
	int pos = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp.at(i) == '<') {
			if (pos > 0)
				pos--;
		}

		else if (tmp.at(i) == '>') {
			if (pos < lst.size())
				pos++;
		}


		else if (tmp.at(i) == '-') {
			if (pos >= 1) {
				pos--;
				itr = lst.begin();
				for (int i = 0; i < pos; i++)
					itr++;
				lst.erase(itr);
			
			}
		}


		else {
			
		
			 itr = lst.begin();
			for (int i = 0; i < pos; i++)
				itr++;
			lst.insert(itr, tmp.at(i));
			pos++;
		}

	}

	for ( itr = lst.begin(); itr != lst.end(); itr++) {
		printf("%c", *itr);

	}




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