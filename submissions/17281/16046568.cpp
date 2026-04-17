#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

vector <int> lineup[51];
vector <int> v;
bool check[10];

int result = 0;
//
int getmaxvalue() {
	int value = 0;
	int inningvalue = 0;
	int i = 0;

	for (int j = 0; j < N; j++) {
		int outcount = 0;
		int player[3] = { 0, };
	
		while (1) {
			
			while (1) {
				if (lineup[j][v[i]] == 0) {
					outcount++;
					if (outcount == 3)
						break;
				}
				else if (lineup[j][v[i]] == 4) {
					for (int i1 = 0; i1 < 3; i1++) {
						value += player[i1];
						player[i1] = 0;
					}
					value++;
				}
				else {
					for (int i1 = 2; i1 >= 0; i1--) {
						if ((i1 + 1 + lineup[j][v[i]]) >= 4) {
							value += player[i1];
							player[i1] = 0;
						}
						else {
							player[i1 + lineup[j][v[i]]] = player[i1];
							player[i1] = 0;
						}
					}
					player[lineup[j][v[i]] - 1]++;
				}
				i = (i + 1) % 9;
			}
			if (outcount == 3) {
				i = (i + 1) % 9;
				break;
			}
		}
	}
	return value;
}


void recursion() {
	if (v.size() == 8) {
		v.insert(v.begin() + 3, 0);
		result = max(result, getmaxvalue());
		v.erase(v.begin() + 3);
		return;
	}


	for (int i = 1; i < 9; i++) {
		if (check[i] == false) {
			check[i] = true;
			v.push_back(i);
			recursion();
			
			check[i] = false;
			v.pop_back();
		}
	}


}


int main() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> tmp;
			lineup[i].push_back(tmp);
		}
	}
	recursion();
	cout << result;
	//system("Pause");
}