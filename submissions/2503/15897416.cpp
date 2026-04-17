#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int N;
class baseball {
public:
	int value;
	int strike;
	int ball;
	baseball(int value, int strike, int ball) {
		this->value = value;
		this->strike = strike;
		this->ball = ball;
	}
};
vector <baseball> v;

vector<int> divde(int x) {
	int x1 = x / 100;
	int x2 = (x % 100) / 10;
	int x3 = (x % 100) % 10;
	return { x1,x2,x3 };
}

bool check(int x) {
	int x1 = x / 100;
	int x2 = (x % 100) / 10;
	int x3 = (x % 100) % 10;
	if (x1 == x2)
		return false;
	if (x2 == x3)
		return false;
	if (x1 == x3)
		return false;
	if (x1 == 0 || x2 == 0 || x3 == 0)
		return false;
	return true;

}

bool baseballgame(int x, int index) {
	vector<int> tmp1 = divde(x);
	vector<int> tmp2 = divde(v[index].value);
	int strike = 0;
	int ball = 0;
	for (int i = 0; i < 3; i++) {
		if (tmp1[i] == tmp2[i])
			strike++;
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j)
				continue;
			if (tmp1[i] == tmp2[j]) {
				ball++;
				break;
			}
		}
	}
	if (v[index].strike == strike && v[index].ball == ball) {
		return true;
	}
	return false;
}
int main()
{
	int count = 0;
	cin >> N;
	int a, b, c;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		v.push_back(baseball(a, b, c));
	}
	for (int i = 100; i <= 999; i++) {
		if (check(i) == true) {
			bool flag = false;
			for (int j = 0; j < v.size(); j++) {
				if (baseballgame(i, j) == false) {
					flag = true;
					break;
				}
			}
			if (flag == false) {
				//cout << i << endl;
				count++;
			}
		}
	}
	cout << count;
	//system("Pause");
}