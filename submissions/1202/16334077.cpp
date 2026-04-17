#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;

vector <pair <int, int>> jewerly;
vector <int> bags;
int main() {
	cin >> N >> K;
	
	int M, V;

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &M, &V);
		jewerly.push_back({ M,V });
	}
	sort(jewerly.begin(), jewerly.end());

	int C;
	for (int i = 0; i < K; i++) {
		scanf("%d", &C);
		bags.push_back(C);
	}
	sort(bags.begin(), bags.end());

	priority_queue <int> q;

	int result = 0;
	int j = 0;
	for (int i = 0; i < bags.size(); i++) {
		while ( j < jewerly.size()) {
			if (jewerly[j].first <= bags[i]) {
				q.push(jewerly[j].second);
				j++;
			}
			else {
				break;
			}
		}
		if (!q.empty()) {
			result += q.top();
			q.pop();
		}
	}
	cout << result;
	//system("Pause");
}