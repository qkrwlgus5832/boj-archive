#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
vector <int> v;
vector <int> v1;


typedef struct  {
	int number0;
	int number1;
}DP;

DP p[10000];


void fibonacci(int n) {

	if (n == 0) {
		p[0].number0 = 1;
		return;

	}
	else if (n == 1) {
		p[1].number1 = 1;
		return;	
	}
	else {
		p[n].number0 = p[n - 1].number0 + p[n - 2].number0;
		p[n].number1 = p[n - 1].number1 + p[n - 2].number1;
	}
}


int main() {
	

	cin >> T;
	int a;
	for (int i = 0; i < T; i++) {
		cin >> a;
		v.push_back(a);
	}
	v1 = v;
	sort(v.begin(), v.end());
	
	for (int i = 0; i <=v[T - 1]; i++) {
		fibonacci(i);
	}

	for (int i = 0; i < T; i++) {
		cout << p[v1[i]].number0 <<" " <<  p[v1[i]].number1<<  endl;
	}
}