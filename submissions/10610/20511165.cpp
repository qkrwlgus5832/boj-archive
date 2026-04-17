#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;

vector <int> v;

int main() {
	string input;
	cin >> input;

	int sum = 0;
	bool flag = false;
	for (int i = 0; i < input.size(); i++) {
		sum += input[i] - '0';
		if (input[i] == '0') // 0이 포함되있으면 정답이 될 수 있음
			flag = true;
		v.push_back(input[i] - '0');
	}

	if (flag == false || sum % 3 != 0) { // 3으로 나누어떨어지지 않으면 정답이 될 수없음
		cout << -1;
		return 0;
	}

	sort(v.begin(), v.end()); // 정렬해서 끝에서부터 출력 -> 최대값

	for (int i = v.size() - 1; i >= 0; i--) {
		printf("%d", v[i]);
	}
	//system("Pause");
}