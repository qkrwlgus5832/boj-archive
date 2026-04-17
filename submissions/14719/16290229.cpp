#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector <int> v;
stack <int> st;
int result = 0;


int getrightmax(int index) {
	int returnvalue = 0;
	for (int i = index + 1; i < v.size(); i++) {
		returnvalue = max(returnvalue, v[i]);
	}
	return returnvalue;
}

void blockcheck() {
	int leftmax = v[0];
	int rightmax;

	for (int i = 0; i < v.size(); i++) {
		if (i == 0 || i == v.size() - 1)
			continue;
	
		leftmax = max(leftmax, v[i - 1]);
		rightmax = getrightmax(i);

		int standard = min(leftmax, rightmax);
		if (v[i] < standard)
			result += standard - v[i];
	}
}

int main() {
	int H, W;
	cin >> H >> W;
	int tmp;
	for (int i = 0; i < W; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	blockcheck();
	cout << result;
	//system("Pause");
}