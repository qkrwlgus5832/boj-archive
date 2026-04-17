#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n;
int N[100020];
char N2[100020];
int i3 = 0;
int i2 = 0;

stack <int> st;
queue <char> q;

int v = 1;


int sequence() {
	while (v <= n) {
		if (v <= N[i2]) {
			st.push(v);
			q.push('+');
			v++;
		}
		
			while (N[i2] == st.top()) {
				st.pop();
				q.push('-');
				i2 = i2 + 1;


				if (st.empty() == 1)
					break;
			}
		}

	

		if (st.empty() == 1 && i2 == n)
			return 1;
		else
			return 0;
	
}



int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> N[i];
	}



	if (sequence() == 1)
	{
		while (!q.empty()) {
			cout << q.front() << endl;
			q.pop();
		}
	}
	else {
		cout << "NO" << endl;
	}


}