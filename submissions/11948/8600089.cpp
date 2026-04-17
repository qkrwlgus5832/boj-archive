#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int A;
int B;
int C;
int D;
int E;
int F;

vector <int> v;
vector <int> v1;
int main() {
	cin >> A;
	cin >> B;
	cin >> C;
	cin >> D;
	cin >> E;
	cin >> F;
	int count = 0;

	
	v.push_back(A);
	v.push_back(B);
	v.push_back(C);
	v.push_back(D);
	v1.push_back(E);
	v1.push_back(F);

	sort(v.begin(), v.end());

	sort(v1.begin(), v1.end());

	 int sum1= v[3] + v[2] + v[1];
	 int sum2 = v1[1];
	 cout << sum1 + sum2;
}