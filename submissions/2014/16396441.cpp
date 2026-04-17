#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <limits.h>
#include <functional>
#include <map>

using namespace std;

int K, N;
vector <int> primenumber;
set <long long> s;
map <long long, bool> m;

int main() {
	cin >> K >> N;
	int tmp;
	int maxvalue = 0;

	for (int i = 0; i < K; i++) {
		cin >> tmp;
		primenumber.push_back(tmp);
		s.insert(tmp);
		m[tmp] = 1;
	}
	int count = 0;

	while (1) {

		if (count == N -1) {
			cout << *s.begin();
			break;
		}
		long long top = *s.begin();
		s.erase(top);
		count++;

		for (int j = 0; j < primenumber.size(); j++) {
			long long maxvalue = *(--s.end());
			if (s.size() + count > N && top * primenumber[j] > maxvalue)
				break;
			if ((long long) top * primenumber[j] <= 0)
				break;
			if (m.count(top * primenumber[j]) ==0) {
				s.insert(top * primenumber[j]);
				m[top* primenumber[j]] = 1;
			}
		}

	}

	//system("Pause");
}