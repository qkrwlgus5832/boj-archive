#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
bool N1[9];
int N, M;


void recursion() {

	if (v.size() == M) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (N1[i] == false) {
			v.push_back(i);
			N1[i] = true;
			recursion();
			N1[i] = false;
			v.pop_back();

		}
		
	}


}

int main() {
	cin >> N >> M;
	recursion();


}