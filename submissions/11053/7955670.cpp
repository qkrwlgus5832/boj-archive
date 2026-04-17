#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector <int> v;
int A[2000];


int n;
int main() {
	int N;
	cin >> N;
	int count = 1;

	for (int i = 0; i < N; i++)
		cin >> A[i];



	for (int n = 0; n < N; n++) {
		int max = A[n];
		for (int i = n + 1; i < N; i++) {
			if (A[i] > max) {
				max = A[i];
				count++;
			}
		}
		v.push_back(count);
		count = 1;
	}

	sort(v.begin(), v.end());


	
		cout << v[v.size() - 1] ;
}
