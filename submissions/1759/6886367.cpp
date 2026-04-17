#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L;
int C;
vector <string> sv;
vector <string> v;
vector<int>::iterator it;

//it = v.begin();

void print() {
	for (int i = 0; i < L; i++) {
		cout << v[i];
 }
	cout << "\n";
}



void recursion(int a, int b) {
	if (a == L) {
		print();
		return;
	}

	for (int i = b; i < C; i++) {
		v.at(a) = sv[i];
		recursion(a + 1, i + 1);
	}
}


int main() {
	cin >> L >> C;

	string name;

	for (int i = 0; i < C; i++) {
		cin >> name;
		sv.push_back(name);
	}

	sort(sv.begin(), sv.end());

	/*for (int i = 0; i < C; i++) {
		cout << sv[i] << " ";
	}
	*/
	 
	for (int i = 0; i < L; i++) {
		v.push_back("a");
	}



	recursion(0, 0);

}