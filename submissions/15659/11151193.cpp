#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int N1[101];
int operator1[4];

vector <int> v;

long long maxr;
long long minr;
int f = 0;
long long calpm(long long result, int flag, long long result2, int operator2) {
	if (flag == 0) {
		result2 = result;
		return result2;
	}
	else if (operator2 ==0) {
		return result2 + result;
	}
	else if (operator2 == 1) {
		return result2 - result;
	}

}
long long calmm() {
	long long result2 = 0;
	long long result = N1[0];
	int operator3 = 0;
	int f = 0; int f1 = 0;
	for (int i = 0; i < N-1; i++) {
		if (v[i] == 0 || v[i] ==1) {
			result2 = calpm(result, f, result2, operator3);
			operator3 = v[i];
			if (f == 0)
				f = 1;
			result = N1[i + 1];
		}
		
		
		else if (v[i] == 2)
			result = result * N1[i + 1];
		else if (v[i] == 3)
			result = result / N1[i + 1];

	}
	result2 = calpm(result, f, result2, operator3);
	return result2;
}


void recursion(int plus, int minus, int mult, int mod) {
	if (v.size() == N-1) {

		if (f == 0) {
			
			maxr = calmm();
			minr =  calmm();
			f = 1;
		}

		else {
			
			maxr = max(maxr, calmm());
			minr = min(minr, calmm());
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
	if (v.size() >= 1)
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