#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <limits.h>
#include <functional>

using namespace std;

int K, N;
vector <int> primenumber;
set <long long> s;

int main() {
	cin >> K >> N;
	int tmp;
	int maxvalue = 0;

	for (int i = 0; i < K; i++) {
		cin >> tmp;
		primenumber.push_back(tmp);
		s.insert(tmp);
	}
	int count = 0;
	while (1) {

		if (count == N -1) {
			cout << *s.begin();
			break;
		}
		int top = *s.begin();
		s.erase(top);
		for (int j = 0; j < primenumber.size(); j++) {
			if (s.size() + count >= N && top * primenumber[j] >= *(--s.end()))
				break;
			if ((long long) top * primenumber[j] <= 0)
				break;
			if (s.find(top * primenumber[j]) == s.end()) {
				s.insert(top * primenumber[j]);
			}
		}

		count++;


	}

	//system("Pause");
}