#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector <int> v;
stack <int> st;
int result = 0;


void blockcheck() {
	int lastblocksize = v[0];
	for (int i = 0; i < v.size(); i++) {
		if (st.size() == 0) {
			st.push(v[i]);
			continue;
		}
		else if (v[i] > st.top()) {
			if (v[i] > lastblocksize) {
				int standard = min(lastblocksize, v[i]);
				while (st.size()) {
					result += standard - st.top();
					st.pop();
				}
				lastblocksize = v[i];
				continue;
			}
			else {
				st.push(v[i]);
			}
		}
		else
			st.push(v[i]);
		lastblocksize = max(lastblocksize, v[i]);
	}
	if (st.size()) {
		int standard = min(lastblocksize, st.top());
		while (st.size()) {
			if (standard - st.top() > 0)
				result += standard - st.top();
			st.pop();
		}
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