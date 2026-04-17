#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <list>
#include <vector>
#include <cstring>
using namespace std;


int T;

char tmp[1000001] = { 0 };
void keylogger() {

	list <char> lst;
	list <char>::iterator itr = lst.begin();
	int pos = 0;
	int ss = strlen(tmp);
	for (int i = 0; i < ss; i++) {
		if (tmp[i] == '<') {
			if (itr != lst.begin()) {
				itr--;
			}
			else
				continue;
		}
		else if (tmp[i] == '>') {
			if (itr != lst.end()) {
				itr++;
			}
			else
				continue;
		}


		else if (tmp[i] == '-') {
			if (itr != lst.begin()) {
				itr = lst.erase(--itr);
			}
			else
				continue;
		}


		else {

			lst.insert(itr, tmp[i]);
		}

	}

	char *result = new char[lst.size()];
	int i = 0;
	for (itr = lst.begin(); itr != lst.end(); itr++) {
		result[i] = *itr;
		i++;

	}
	result[i] = '\0';



	printf("%s\n", result);

}

int main() {
	cin >> T;





	for (int i = 0; i < T; i++) {
		scanf("%s", &tmp);
		keylogger();


	}



}