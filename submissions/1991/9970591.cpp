#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector <pair <char, char>> v;
int N;

char leftt;
char node;
char rightt;


void recursion(int x) {
	if (x == '.')
		return;
	printf("%c", x+'A');
	
	recursion(v[x].first);
	recursion(v[x].second);


}
void recursion2(int x) {
	if (x == '.')
		return;
	recursion2(v[x].first);
	printf("%c", x + 'A');
	recursion2(v[x].second);

}
void recursion3(int x) {
	if (x == '.')
		return;
	recursion3(v[x].first);
	recursion3(v[x].second);
	printf("%c", x + 'A');


}


int main() {
	cin >> N;

	v.resize(100);

	for (int i = 0; i < N; i++) {
		cin >> node >> leftt >> rightt;
		node = node - 'A';
		if (leftt != '.') {
			leftt = leftt - 'A';

		}

		if (rightt != '.') {
			rightt = rightt - 'A';
		}
		v[node].first = leftt;
		v[node].second = rightt;
	}


	recursion(0);
	cout << endl;
	recursion2(0);
	cout << endl;
	recursion3(0);

}