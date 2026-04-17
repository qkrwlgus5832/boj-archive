#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>

using namespace std;

int N;

stack <string> st;

int goodword(string a) {
	for (unsigned int i = 0; i < a.size(); i++) {
		string tmp;
		tmp = a.at(i);
		string tmp2;
		if (st.empty()) {
			st.push(tmp);
		}
		else if (!st.empty() && tmp != st.top()) {
			st.push(tmp);
		}
		else {
			st.pop();
		}
	}

	if (st.empty() == 1) {
		return 1;
	}
	else {
		while (!st.empty()) 
		st.pop();
		return 0;
	}
	

}




int main() {
	
	int count = 0;
	cin >> N;
	string p[101];
	for (int i = 0; i < N; i++) {
		cin >> p[i];
		
	}




	for (int i = 0; i < N; i++) {
		if (goodword(p[i]) == 1)
			count = count + 1;
	}
	cout << count;
	

}
