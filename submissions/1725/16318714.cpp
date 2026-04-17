#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N;

pair <int, int> histMaxArea[100001];
vector <int> histarea;

void searchleft() {
	stack <pair <int, int>> st;
	for (int i = 0; i < histarea.size(); i++) {
		if (st.size() == 0)
			st.push({ histarea[i], i });
		else if (st.top().first < histarea[i]) {
			histMaxArea[i].first = 0;
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
			if (st.size() == 0) {
				aimindex = -1;
			}
			histMaxArea[i].first = i - aimindex -1;
			st.push({ histarea[i], i });
		}
	}
}
void searchright() {
	stack <pair <int, int>> st;
	for (int i = histarea.size() - 1; i >= 0; i--) {
		if (st.size() == 0)
			st.push({ histarea[i], i });
		else if (st.top().first < histarea[i]) {
			histMaxArea[i].second = 0;
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
			if (st.size() == 0) {
				aimindex = histarea.size();
			}
			
			histMaxArea[i].second = abs(i - aimindex)-1;
			
			
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
	searchleft();
	searchright();
	int result = 0;
	for (int i = 0; i < N; i++) {
		int tmp = histMaxArea[i].first + histMaxArea[i].second;
		int area = histarea[i] + tmp * histarea[i];
		result = max(result, area);
	}
	cout << result;
	//system("Pause");
}