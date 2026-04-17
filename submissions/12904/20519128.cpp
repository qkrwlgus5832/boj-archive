#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>

using namespace std;

string S, input;
deque <char> T; // pop_front, pop_back을 쉽게 하기 위해서 deque으로 구현 


int main() {
	cin >> S;
	cin >> input;
	
	int diff = input.size() - S.size(); 

	for (int i = 0; i < input.size(); i++) {
		T.push_back(input[i]);
	}

	bool reserve = false;

	for (int i = 0; i < diff; i++) { // T와 S의 차이만큼 반복
		if (T.back() == 'A') {
			if (reserve)
				T.pop_front();
			else
				T.pop_back();
		} 
		else {
			if (reserve)
				T.pop_front();
			else
				T.pop_back();
			reserve = !reserve; // 뒤집어준다.
		}
	}

	//T와 S가 같은지 확인
	if (reserve) { // 거꾸로 확인
		for (int i = 0; i < S.size(); i++) {
			if (T[T.size() - 1 - i] != S[i]) {
				cout << 0;
				return 0;
			}
		}
		cout << 1;
	}
	else { 
		for (int i = 0; i < S.size(); i++) {
			if (T[i] != S[i]) {
				cout << 0;
				return 0;
			}
		}
		cout << 1;
	}
	//system("Pause");
}