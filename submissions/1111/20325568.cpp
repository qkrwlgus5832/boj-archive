#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector <int> v;

int getAnswer(int a, int b, int beforevalue) {
	return a * beforevalue + b;
}

pair <int,int> getAandB(int firstValue, int secondValue, int thirdValue) {
	int tmp = secondValue - firstValue;
	int value = thirdValue - secondValue;

	if (tmp != 0 && value % tmp == 0) {
		int a = value / tmp;
		return { a, secondValue - (firstValue * a) };
	}
	else if (tmp == 0 && secondValue == thirdValue)
		return { 1,0 };

	cout << "B";
	exit(0);
}

int main() {
	int N;
	cin >> N;
	int tmp;

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	
	if (N == 1) {
		cout << "A";
	}
	else if (N == 2) {
		if (v[0] == v[1]) 
			cout << v[0];
		else
			cout << "A";
	}
	else {
		pair <int, int> AB = getAandB(v[0], v[1], v[2]);
		for (int i = 3; i < N; i++) {
			if (v[i] != v[i - 1] * AB.first + AB.second) {
				cout << "B";
				exit(0);
			}
		}
		cout << v[v.size() - 1] * AB.first + AB.second;
	}
	
	//system("Pause");

}