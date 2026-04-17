#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <functional>

using namespace std;

int K, N;
vector <int> primenumber;
set <int> s;

int main() {
	cin >> K >> N;
	int tmp;

	for (int i = 0; i < K; i++) {
		cin >> tmp;
		primenumber.push_back(tmp);
		s.insert(tmp);
	}

	int maxvalue = 0;

	int count = 1;
	while (1) {

		if (count == N) {
			break;
		}
		bool flag = false;
		auto beginindex = s.begin();
		int currentsize = s.size();
		for (int i = 0; i < currentsize; i++) {
			int top = *beginindex;
			beginindex++;
			for (int j = 0; j < primenumber.size(); j++) {
				if (s.size() >= N && top * primenumber[j] >= maxvalue)
					break;
				if (s.find(top * primenumber[j]) == s.end()) {
					s.insert(top * primenumber[j]);
					if (s.size() >= N) {
						maxvalue = max(maxvalue, top * primenumber[j]);
					}
					flag = true;
				}
			}
		}
		count++;
		
	}

	while (s.size() > N) {
		s.erase(*(--s.end()));
	}
	cout << *(--s.end());
	//system("Pause");
}