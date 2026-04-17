#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector <int> heights;

int main() {
	vector<int> answer;
	stack <pair <int, int>> st;
	int N, tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		heights.push_back(tmp);
	}
	for (int i = 0; i < heights.size(); i++) {
		if (st.size() == 0) {
			st.push({ heights[i], i });
			answer.push_back(0);
		}
		else if (st.top().first <= heights[i]) {
			while (st.size() && st.top().first <= heights[i]) {
				st.pop();
			}
			if (st.size()) {
				answer.push_back(st.top().second + 1);
			}
			else {
				answer.push_back(0);
			}
			st.push({ heights[i], i });
		}
		else if (st.top().first > heights[i]) {
			answer.push_back(st.top().second + 1);
			st.push({ heights[i], i });
		}
	}
	for (int i = 0; i < answer.size(); i++)
		printf("%d ", answer[i]);
	//system("Pause");
}