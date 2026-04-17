#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

deque<int> st;

int stpush(int x) {
	if (st.size() == 0) {
		st.push_back(x);
		return 0;
	}
	int count = 0;
	
	int index = st.size() - 1;
	while (1) {
		if (st.size() == 0)
			break;
		if (index < 0)
			break;
		if (st[index] < x) {
			st.pop_back();
			index--;
			count++;
		}
		else if (st[index] > x) {
			count++;	
			break;
		}
		else {
			count++;
			index--;
			continue;
		}
		
	}
	
	st.push_back(x);
	return count;
}

int main() {


	int N;
	cin >> N;
	int tmp;
	long long result = 0;



	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		result += stpush(tmp);

	}


	cout << result;
	//system("Pause");
}