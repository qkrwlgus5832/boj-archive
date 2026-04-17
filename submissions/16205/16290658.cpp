#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;



vector <string> splitToWord(int number, string variablename) {
	vector <string> returnvalue;
	if (number == 3) {
		variablename[0] = variablename[0] - 'A' + 'a';
	}
	if (number == 1 || number == 3) {
		int lastindex = 0;
		for (int i = 0; i < variablename.size(); i++) {
			if (variablename[i] >= 'A' && variablename[i] <= 'Z') {
				variablename[i] = variablename[i] - 'A' + 'a';
				returnvalue.push_back(variablename.substr(lastindex, i - lastindex));
				lastindex = i;
			}
			
		}
		returnvalue.push_back(variablename.substr(lastindex, variablename.size() - lastindex));
	}
	else if (number == 2) {
		int lastindex = 0;
		for (int i = 0; i < variablename.size(); i++) {
			if (variablename[i] == '_') {
				returnvalue.push_back(variablename.substr(lastindex, i - lastindex));
				lastindex = i + 1;
			}

		}
		returnvalue.push_back(variablename.substr(lastindex, variablename.size() - lastindex));
	}
	return returnvalue;
}


string converToCase(int number, vector <string> splitword) {
	
	string returnvalue = "";
	if (number == 1 || number == 3) {
		for (int i = 0; i < splitword.size(); i++) {
			if (i > 0)
				splitword[i][0] = splitword[i][0] - 'a' + 'A';
			returnvalue += splitword[i];
		}
	}
	else if (number == 2) {
		for (int i = 0; i < splitword.size(); i++) {
			if (i > 0)
				returnvalue += '_';
			returnvalue += splitword[i];
		}
	}
	if (number == 3) {
		returnvalue[0] = returnvalue[0] - 'a' + 'A';
	}
	return returnvalue;
}
int main() {
	int number;
	string variablename;
	cin >> number;
	cin >> variablename;
	vector <string> splitword = splitToWord(number, variablename);
	for (int i = 1; i <= 3; i++) {
		if (number == i) {
			cout << variablename << endl;
		}
		else {
			cout << converToCase(i, splitword) << endl;
		}
	}
	//system("Pause");

}