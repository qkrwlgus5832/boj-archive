#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N;
string input;
int alphavalue[26];
stack <double> st;


double calculate(double first, double second, double oper) {
	if (oper == '+')
		return  first + second;
	else if (oper == '-')
		return  first - second;
	else if (oper == '*')
		return first * second;
	else if (oper == '/')
		return  first / second;
}

int main() {
	cin >> N;
	cin >> input;
	for (int i = 0; i < N; i++) {
		cin >> alphavalue[i];
	}

	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z')
			st.push(alphavalue[input[i] - 'A']);
		else {
			double second = st.top();
			st.pop();
			double first = st.top();
			st.pop();
			double result = calculate(first, second, input[i]);
			st.push(result);
		}
	}
	printf("%.2f", st.top());
	//system("Pause");
}