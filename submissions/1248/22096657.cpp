#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;


vector <char> v[11];
int N;


bool check(int sum, char oper) {
	if (oper == '-') {
		if (sum < 0)
			return true;
	}
	if (oper == '+') {
		if (sum > 0)
			return true;
	}
	if (oper == '0') {
		if (sum == 0)
			return true;
	}
	return false;
}

bool checkIfAnswer(vector <int>& result) {

	for (int i = 1; i <= N; i++) {
		int tmp = 0;
		for (int j = i - 1, i1 =0; j < N; j++, i1++) {
			tmp += result[j];
			if (check(tmp, v[i][i1]) == false)
				return false;

		}
	}
	return true;
}


void recursion(int depth, int sum, vector <int> result) {
	if (depth == N + 1) {
		if (checkIfAnswer(result)) {
			for (int i = 0; i < result.size(); i++) {
				cout << result[i] << " ";
			}
			exit(0);
		}
			
		return;
	}
	if (v[depth][0] == '+') {
		for (int i = 1; i <= 10; i++) {
			if (check(sum + i, v[1][depth - 1])) {
				result.push_back(i);
				recursion(depth  + 1, sum + i, result);
				result.pop_back();
			}
		}
	}
	else if (v[depth][0] == '-'){
		for (int i = -10; i <= -1; i++) {
			if (check(sum + i, v[1][depth - 1])) {
				result.push_back(i);
				recursion(depth + 1, sum + i, result);
				result.pop_back();
			}
		}
	}
	else {
		result.push_back(0);

	}
}

int main() {
	
	cin >> N;

	char ch;

	for (int i = N, i1= 1; i >=1; i--, i1++) {
		for (int j = 0; j < i; j++) {
			cin >> ch;
			v[i1].push_back(ch);
		}
	}

	recursion(1, 0, {});
	//system("Pause");
}
