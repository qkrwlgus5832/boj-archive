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
	for (int i = 1; i <= n; i++) {
		if (N[i2] != i) {
			st.push(i);
			q.push('+');
		}
		else {
			q.push('+');	
			q.push('-');
			i2 = i2 + 1;
			int q2 = st.size();
			for (int j = 0; j <q2; j++) {
				if (N[i2] == st.top()) {
					st.pop();
					q.push('-');
					i2 = i2 + 1;
				}
				
			}
		
		}
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

	cout << endl;

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