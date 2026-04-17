#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n;
int N[100001];
int N2[100001];
stack <int> st;
queue <char> q;
int sequence() {
	int i2 = 0;
	int i = 1;
	while (1) {
		if (i2 == n+1)
			break;
		if (i <= N[i2]) {
			st.push(i);
			q.push('+');
			i = i + 1;
		}

		if (st.top() == N[i2]) {
			st.pop();
			q.push('-');
			i2 = i2 + 1;
		}
		else if (N[i2] < st.top() || i>n)
			break;
	}

		
	


	if (st.empty() == 1)
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