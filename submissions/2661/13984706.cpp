#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N;

vector <int> v;

bool flag = 0;

bool check() {
	if (v.size() == 1)
		return false;
	for (int i = 1; i <= v.size() / 2; i++) {
		bool flag = false;
		for (int j = 0; j < i; j++) {
			int dd = v.size() - 1 - j;

			if (v[dd] != v[dd - i]) {
				flag = true;
			}
		}
		if (flag == false) {
			return true;
		}
	}
	return false;
}
void recursion() {
	if (flag == true)
		return;

	if (v.size() == N) {
		flag = true;
		for (int i = 0; i < v.size(); i++)
			printf("%d", v[i]);
		return;
	}

	for (int i = 1; i <= 3; i++) {
		v.push_back(i);
		if (check() == false) {
			recursion();
		}
		else
			v.pop_back();
	}
	if (v.size() >=1)
		v.pop_back();
}

int main() {
	cin >> N;

	recursion();


	//system("Pause");
}