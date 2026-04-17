#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;

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
		auto iter= lower_bound(v.begin(), v.end(), M -v[i]);
		if (iter != v.end()) {
			if (*iter + v[i] == M) {
				v.erase(iter);
				count++;
			}
		}

	}
	cout << count;
	//system("Pause");
}