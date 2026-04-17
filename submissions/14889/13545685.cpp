#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


int N;
int N1[21][21];



vector <int> v;

int result = -1;

int compare() {
	int value = 0;
	int comparevalue = 0;
	vector <int> v2;
	bool check[21] = { false, };

	for (int j=0; j<v.size(); j++) {
		check[v[j]] = true;
		for (int i = j; i < v.size(); i++) {
			if (i == j)
				continue;
			else {
				value += N1[v[i]][v[j]];
				value += N1[v[j]][v[i]];
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (check[i] == false)
			v2.push_back(i);
	}

	for (int j = 0; j<v2.size(); j++) {
		for (int i = j; i < v2.size(); i++) {
			if (i == j)
				continue;
			else {
				comparevalue += N1[v2[i]][v2[j]];
				comparevalue += N1[v2[j]][v2[i]];
			}
		}
	}
	return abs(comparevalue - value);
}


void recursion(int i) {
	if (v.size() == N / 2) {
		if (result == -1) {
			result = compare();
		}
		else {
		
			result = min(result, compare());
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << " ";
			cout << result << endl;
		}
		v.pop_back();
		return;
	}
	for (int i1 = i; i1 <= N; i1++) {
		v.push_back(i1);
		recursion(i1 + 1);
	}
	if (v.size() >= 1)
		v.pop_back();

}
int main() {
	cin >> N;
	int S;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &S);
			N1[i][j] = S;
		}
	}

	recursion(1);

	cout << result;
	//system("Pause");
}