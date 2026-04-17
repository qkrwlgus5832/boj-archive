#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int leef[100];
int eras;
vector <int> v[100];
int recursion(int i) {

	int count = 0;

	int f = 0;
	for (int i1 = 0; i1 < v[i].size(); i1++) {
		if (v[i][i1] == eras)
			continue;
		else {
			count += recursion(v[i][i1]);
			f = 1;
		}
	}
	if (f == 0)
		return 1;

	return count;
}

int N;
int main() {
	cin >> N;
	int parent;
	int root;

	for (int i = 0; i < N; i++) {
		cin >> parent;
		if (parent == -1)
			root = i;
		v[parent].push_back(i);
	}

	cin >> eras;


	if (root == eras)
		cout << 0;
	else
	cout << recursion(root);


}