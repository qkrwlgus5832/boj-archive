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
	priority_queue <int, vector<int>, less<int>> maxheap;
	for (int i = 0; i < K; i++) {
		cin >> tmp;
		primenumber.push_back(tmp);
		s.insert(tmp);
		maxheap.push(tmp);
	}
	
	while (1) {
		bool flag = false;
		auto beginindex = s.begin();
		for (int i = 0; i < s.size(); i++) {
			int top = *beginindex;
			beginindex++;
			for (int j = 0; j < primenumber.size(); j++) {
				if (maxheap.size() >= N && top * primenumber[j] >= maxheap.top())
					break;
				if (s.find(top * primenumber[j]) == s.end()) {
					s.insert(top * primenumber[j]);
					maxheap.push(top * primenumber[j]);
					flag = true;
				}
			}
		}
		if (flag == false) {
			break;
		}
	}

	while (maxheap.size() > N) {
		maxheap.pop();
	}
	cout << maxheap.top();
	//system("Pause");
}