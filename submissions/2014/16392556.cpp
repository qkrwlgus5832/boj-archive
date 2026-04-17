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
	int maxvalue = 0;

	for (int i = 0; i < K; i++) {
		cin >> tmp;
		primenumber.push_back(tmp);
		s.insert(tmp);
		maxvalue = tmp;
	}



	int count = 1;
	while (1) {

		if (count == N) {
			cout << *s.begin();
			break;
		}
		auto beginindex = s.begin();
		int currentsize = s.size();
		int top = *beginindex;
		s.erase(top);
		for (int j = 0; j < primenumber.size(); j++) {
			if (s.size() >= N && top * primenumber[j] >= maxvalue)
				break;
			if (s.find(top * primenumber[j]) == s.end()) {
				s.insert(top * primenumber[j]);
				if (s.size() >= N) {
					maxvalue = max(maxvalue, top * primenumber[j]);
				}
			}
		}
	
		count++;
		
		
	}

	//system("Pause");
}