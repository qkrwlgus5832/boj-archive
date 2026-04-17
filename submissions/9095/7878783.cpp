#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

int tmp = 0;
int recursion(int N) {

	if (N == 1) {
		return 1;
	}
	else if (N == 2) {
		return 2;
	}

	else if (N == 3) {


		return 4;
	}
	else {
		recursion(N - 1);

		return recursion(N - 1) + recursion(N - 2) + recursion(N - 3);
		
	}

}




int n;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		v.push_back(recursion(n));
	}

	for (int i = 0; i < T; i++) {

		cout << v[i] << endl;
	}
}




