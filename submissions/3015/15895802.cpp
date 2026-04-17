#define _CRT_SECURE_NO_WARNINGS
#include <stack>
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
		index = st.size() - 1;
	}
	
	st.push_back(x);
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int tmp;
	long long result = 0;



	for (int i = 0; i < N; i++) {
		cin >> tmp;
		result += stpush(tmp);

	}


	cout << result;
	//system("Pause");
}