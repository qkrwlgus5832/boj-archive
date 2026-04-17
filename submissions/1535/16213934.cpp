#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L[21];
int J[21];

int result = 0;
vector <int> v;
int N;


void recursion(int index, int posion, int joy){
	if (posion <= 0)
		return;
	
	result = max(result, joy);

	for (int i = index; i < N; i++) {
		v.push_back(i);
		recursion(i+1 , posion- L[i], joy + J[i]);
		v.pop_back();
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> L[i];
	for (int j = 0; j < N; j++)
		cin >> J[j];

	recursion(0, 100, 0);
	cout << result;
	//system("Pause");
}