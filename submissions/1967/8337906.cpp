#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


char graph[10001][10001];

int n2;
stack <int> st;
vector <int> v2;
int left(int n, int sum2) {
	bool check[10001] = { false, };
	vector <int> v;
	st.push(n);
	check[n] = true;
	int sum = sum2;
	while (!st.empty()) {
		int n1 = st.top();
		int f = 0;
		int f2 = 0;	
		for (int i = 1; i <= n2; i++) {

			if (graph[n1][i] > 0) {
				f2 = f2+1;
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
				 v.push_back(sum);
				 sum = sum - graph[x2][x1];
			 }
			 else {
				 v.push_back(sum);
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
	if (v.size() >= 1) {
		sort(v.begin(), v.end());

		return v[v.size() - 1];
	}
	
	

}
int right(int n, int sum2) {
	bool check[10001] = { false, };
	vector <int> v;
	st.push(n);
	check[n] = true;
	int sum = sum2;
	while (!st.empty()) {
		int n1 = st.top();
		int f = 0;
		int f2 = 0;
		for (int i = 1; i <= n2; i++) {

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
				v.push_back(sum);
				sum = sum - graph[x2][x1];
			}
			else {
				v.push_back(sum);
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
	if (v.size() >= 1) {
		sort(v.begin(), v.end());

		return v[v.size() - 1];
	}



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
		int rtmp = 0;


		
		for (int i = 1; i <= n2; i++) {
			int f = 0;
			for (int i2 = 1; i2 <= n2; i2++) {

				if (graph[i][i2] > 0 && f == 0) {
					ltmp = left(i2, graph[i][i2]);
					f = f + 1;
				}
				else if ((graph[i][i2] > 0 && f ==0 && ltmp ==0) || (graph[i][i2] > 0 && f == 1 && ltmp > 0))
					rtmp = right(i2, graph[i][i2]);
			}
				
				v2.push_back(ltmp + rtmp);
				
				ltmp = 0;
				rtmp = 0;
			}

		}
	

		if (v2.size() >= 1) {
			sort(v2.begin(), v2.end());

			cout << v2[v2.size() - 1];
		}
		
		
}


