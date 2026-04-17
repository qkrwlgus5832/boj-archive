#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int N1[101];
int operator1[4];

vector <int> v;
int f = 0;
long long maxr;
long long minr;

long long calcul() {
	long long result = 0;

	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			if (v[i] == 0)
				result = result + N1[i] + N1[i + 1];

			if (v[i] == 1)
				result = result + N1[i] - N1[i + 1];
			if (v[i] == 2)
				result = result + N1[i] * N1[i + 1];
			if (v[i] == 3)
				result = result + N1[i] / N1[i + 1];
		}
		else {
			if (v[i] == 0)
				result = result +N1[i + 1];

			if (v[i] == 1)
				result = result - N1[i + 1];
			if (v[i] == 2)
				result = result * N1[i + 1];
			if (v[i] == 3)
				result = result / N1[i + 1];
		}
	}

	return result;
}

void recursion(int plus, int minus, int mult, int mod) {
	if (plus == 0 && minus == 0 && mult == 0 && mod == 0) {
		
		if (f == 0) {
			maxr = calcul();
			minr = calcul();
			f = 1;
		}

		else {
			maxr = max(maxr, calcul());
			minr = min(minr, calcul());
		}

		

		v.pop_back();
		return;
	}
	if (plus >= 1) {
		v.push_back(0);
		recursion(plus - 1, minus, mult, mod);
	
	}

	if (minus >= 1) {
		v.push_back(1);
		recursion(plus, minus - 1, mult, mod);
	
	}

	if (mult >= 1) {
		v.push_back(2);
		recursion(plus, minus, mult - 1, mod);
	
	}

	if (mod >= 1) {
		v.push_back(3);
		recursion(plus, minus, mult, mod - 1);

	}
	if (v.size() >=1)
	v.pop_back();

}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> N1[i];

	int plus, minus, mult, mod;

	cin >> plus >> minus >> mult >> mod;





	recursion(plus, minus, mult, mod);

	cout << maxr << endl;
	cout << minr;

}