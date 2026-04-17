#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


char graph[10001][10001];

struct p {
	int value;
	int index;
};
int n2;
stack <int> st;
vector <int> v2;
int left(int n, int sum2) {
	bool check[10001] = { false, };
	vector <int> v;
	st.push(n);
	int maxsum = 0;
	check[n] = true;
	int sum = sum2;
	while (!st.empty()) {
		int n1 = st.top();
		int f = 0;
		int f2 = 0;
		for (int i = 1; i <= 10000; i++) {

			if (graph[n1][i] > 0) {
				f2 = f2 + 1;
				if (check[i] == false) {
					st.push(i);
					check[i] = true;
					f = 1;
					sum = sum + graph[n1][i];
					break;
				}
			}


		}

		if (f == 0 && f2 == 0) {
			if (st.size() >= 2) {
				int x1 = st.top();
				st.pop();
				int x2 = st.top();
				if (maxsum <= sum)
					maxsum = sum;
				sum = sum - graph[x2][x1];
			}
			else {
				if (maxsum <= sum)
					maxsum = sum;
				st.pop();
			}
		}
		else if (f == 0) {
			if (st.size() >= 2) {
				int x1 = st.top();
				st.pop();
				int x2 = st.top();
				sum = sum - graph[x2][x1];
			}
			else {
				st.pop();

			}
		}
	}
	
	return maxsum;


}

int main() {

	cin >> n2;

	int a;
	int b;
	int c;
	for (int i = 0; i < n2 - 1; i++) {
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	if (n2 == 1)
		cout << "0";
	else {
		int ltmp = 0;



		for (int i = 1; i <= 10000; i++) {
			int f = 0;
			vector <p> v;
			int max = 0;
			int max2 = 0;
			int i3 = 0;
			for (int i2 = 1; i2 <= 10000; i2++) {

				if (graph[i][i2] > 0) {
					ltmp = left(i2, graph[i][i2]);
					if (max <= ltmp) {
						max = ltmp;
						i3 = i2;
					}
					struct p p1;
					p1.value = ltmp;
					p1.index = i2;
					v.push_back(p1);
				}
				ltmp = 0;
			}


			if (v.size() >= 2) {
				for (int j = 0; j<v.size(); j++) {
					if (max2 <= v[j].value) {
						if (v[j].index != i3)
							max2 = v[j].value;
					}
				}
				v2.push_back(max + max2);
			}
			else if (v.size() == 1) {
				v2.push_back(max + max2);
			}

		}

	}


	if (v2.size() >= 1) {
		sort(v2.begin(), v2.end());

		cout << v2[v2.size() - 1];
	}


}