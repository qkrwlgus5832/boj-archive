#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

deque<pair <int, int>> st;

int stpush(int x) {
	if (st.size() == 0) {
		st.push_back(make_pair(x,1));
		return 0;
	}
	int count = 0;
	
	int index = st.size() - 1;
	while (1) {
		if (st.size() == 0)
			break;
		if (index < 0)
			break;
		if (st[index].first < x) {
			count += st[index].second;
			st.pop_back();
			index--;
			
		}
		else if (st[index].first > x) {
			count++;	
			break;
		}
		else {
			st[index].second++;
			if (st.size() == 1)
				return st[index].second - 1 + count;
			else
				return st[index].second + count;
		}
		
	}
	
	st.push_back(make_pair(x,1));
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