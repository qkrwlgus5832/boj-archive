#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int leef[51];
vector <int> v[51];
int recursion(int i) {

	int count = 0;
	if (v[i].size() == 0) {
		leef[i] = 1;
		return 1;
	}

	for (int i1 = 0; i1 < v[i].size(); i1++) {
		count += recursion(v[i][i1]);
	}

	leef[i] = count;
	return count;
}

int N;
int main() {
	cin >> N;
	int parent;
	int root;
	int eras;
	for (int i = 0; i < N; i++) {
		cin >> parent;
		if (parent == -1)
			root = i;
		v[parent].push_back(i);
	}

	cin >> eras;



	recursion(root);

	if (leef[root] - leef[eras] == 0)
		cout << 1;
	else
	cout << leef[root] - leef[eras];
}