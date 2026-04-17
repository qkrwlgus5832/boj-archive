#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N;

vector<int> histMaxArea[100001];
vector <int> histarea;

void search(int startindex, int endindex, int dir) {
	stack <pair <int, int>> st;
	for (int i = startindex; i != endindex; i += dir) {
		if (st.size() == 0) {
			st.push({ histarea[i], i });
			histMaxArea[i].push_back(0);
		}
		else if (st.top().first < histarea[i]) {
			histMaxArea[i].push_back(0);
			st.push({ histarea[i], i });
		}
		else if (st.top().first >= histarea[i]) {
			int aimindex;
			while (st.size()) {
				if (st.top().first >= histarea[i]) {
					aimindex = st.top().second;
					st.pop();
				}
				else {
					aimindex = st.top().second;
					break;
				}
			}
			if (st.size() == 0 && dir == 1) {
				aimindex = -1;
			}
			else if (st.size() == 0 && dir == -1) {
				aimindex = histarea.size();
			}
			histMaxArea[i].push_back(abs(i - aimindex) -1);
			st.push({ histarea[i], i });
		}
	}
}

int main() {

	cin >> N;
	histarea.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &histarea[i]);
	}
	search(0, histarea.size(), 1);
	search(histarea.size() - 1, -1, -1);
	int result = 0;
	for (int i = 0; i < N; i++) {
	
		int tmp = histMaxArea[i][0] + histMaxArea[i][1];
	
		int area = histarea[i] + tmp * histarea[i];
		result = max(result, area);
	}
	cout << result;
	//system("Pause");
}