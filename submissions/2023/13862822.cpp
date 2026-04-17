#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;


int N;

vector <int> v;

bool issosu(int x) {
	int sqrtx = sqrt(x);

	if (x == 1)
		return false;

	for (int i = 2; i <= sqrtx; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int getvalue() {
	int x = 0;
	for (int i = 0; i < v.size(); i++)
		x = x * 10 + v[i];
	return x;

}
void recursion(int i) {
	if (v.size() == N) {
		int x = getvalue();
		if (issosu(x) == true)
			printf("%d\n", x);
		v.pop_back();
		return;
	}
	else if (v.size() >=1 ){
		int x = getvalue();
		if (issosu(x) == false) {
			v.pop_back();
			return;
		}
	}
	for (int i = 1; i <= 9; i++) {
		v.push_back(i);
		recursion(i + 1);

	}
	if (v.size() >= 1)
		v.pop_back();
}

int main() {
	cin >> N;


	recursion(0);
	//system("Pause");
}