#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
vector <int> result;
bool check[9];
bool resultflag = false;
void recursion(int index, int dwarfcount, int heightcount) {
	if (dwarfcount == 7) {
		if (heightcount == 100) {
			for (int i = 0; i < 9; i++) {
				if (check[i] == true) {
					result.push_back(v[i]);
				}
			}
			resultflag = true;
		}
		return;
	}
	for (int i = index; i < 9; i++) {
		check[i] = true;
		recursion(i + 1, dwarfcount + 1, heightcount + v[i]);
		if (resultflag == true)
			return;
		check[i] = false;
	}
}


int main() {
	int input;
	for (int i = 0; i < 9; i++) {
		cin >> input;
		v.push_back(input);
	}

	recursion(0, 0, 0);
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	//system("Pause");
}