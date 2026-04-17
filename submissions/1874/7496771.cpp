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

int N3[100020];
queue <char> q;

int v = 1;

void push_1() {
	while (N[i2] != v) {
		N3[i3++] = v;
		q.push('+');
		v = v + 1;
	}
	N3[i3++] = v;
	q.push('+');

}

int sequence() {
	while (v != n) {
		if (N[i2] != v) {
			push_1();
		}
		while (N[i2] == N3[i3 - 1]) {
			N3[i3 - 1] = 0;
			i3 = i3 - 1;

			q.push('-');
			i2 = i2 + 1;
		}
	}
	
	if (i3==0 &&i2==n)
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