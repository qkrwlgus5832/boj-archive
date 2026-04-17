#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
char s[100001];
stack <char> st;
int pipe() {
	int count = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '(')
			st.push('(');
		else if (s[i - 1] == '(') {
			st.pop();
			count = count + st.size();
		}
		else {
				st.pop();
				count = count + 1;
			}
		}
	
	return count;
}

int main() {
	cin >> s;

	cout << pipe() << endl;


}