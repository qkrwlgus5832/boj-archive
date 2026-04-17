#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int n;
int N[1000001];
stack <int> st;
vector <char> q;
int sequence() {
	int i2 = 0;
	int i = 1;
	while (1) {
		if (i2 == n)
			break;
		if (i <= N[i2]) {
			st.push(i);
			q.push_back('+');
			i = i + 1;
		}

		if (st.top() == N[i2]) {
			st.pop();
			q.push_back('-');
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
		scanf("%d",  &N[i]);
	}



	if (sequence() == 1)
	{
		for (int i = 0; i < q.size(); i++) {
			printf("%c\n", q[i]);
		}
	}
	else {
		cout << "NO" << endl;
	}


}