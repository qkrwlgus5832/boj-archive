#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector <int> v;
map <int, int> m;

bool check[15001];

int main() {
	int N;
	cin >> N;
	int M;
	cin >> M;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		auto iter = lower_bound(v.begin() + i + 1, v.end(), M - v[i]);
		int index = iter - v.begin();
		if (iter != v.end()) {
			if (*iter + v[i] == M && check[index] == false) {
				count++;
				check[index] = true;
				check[i] = true;
			}
		}
	}
	cout << count;
	//system("Pause");
}