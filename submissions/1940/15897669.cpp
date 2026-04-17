#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector <int> v;
map <int, int> m;


int main() {
	int N;
	cin >> N;
	int M;
	cin >> M;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (m.count(tmp) == 0) {
			m[tmp] = 1;
			v.push_back(tmp);
		}
		else
			m[tmp]++;
	}

	sort(v.begin(), v.end());
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		auto iter= lower_bound(v.begin(), v.end(), M -v[i]);
		if (iter != v.end()) {
			if (*iter + v[i] == M) {
				if (m[*iter] >= 1) {
					m[*iter]--;
					m[v[i]]--;
					count++;
				}
			}
		}

	}
	cout << count;
	//system("Pause");
}