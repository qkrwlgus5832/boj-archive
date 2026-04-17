#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


string getAnswer(string primitive, string testcase) {
	bool flag = false;

	int index = 0;

	for (int i = testcase.size() - 1; i >= 0; i--) {
		if (testcase[i] >= 'a' && testcase[i] <= 'z') {
			if (flag == false) {
				primitive += " ";
				flag = true;
				index = i;
				break;
			}
		
		}
		else if (testcase[i] >= 'A' && testcase[i] <= 'Z') {
			if (flag == false) {
				primitive += " ";
				flag = true;
				index = i;
				break;
			}

		}
		else if (testcase[i] == '[') {
			primitive += ']';
		}
		else if (testcase[i] == ']') {
			primitive += '[';
		}
		else {
			primitive += testcase[i];
		}
		
	}
	
	string tmp = "";
	for (int i = 0; i <= index; i++) {
		tmp += testcase[i];
	}
	return primitive + tmp +';';
}
int main() {
	string input;
	getline(cin, input);

	string tmp = "";

	string primitive = "";

	vector <string> v;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ' ') {
			if (primitive == "")
				primitive = tmp;
			tmp = "";
		}
		else if (input[i] == ',') {
			v.push_back(tmp);
			printf("%s\n", getAnswer(primitive, tmp).c_str());
			tmp = "";
		}
		else {
			tmp += input[i];
		}
	}
	tmp.pop_back();
	v.push_back(tmp);
	printf("%s\n", getAnswer(primitive, tmp).c_str());
	//system("Pause");
}