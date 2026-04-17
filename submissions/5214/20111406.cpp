#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K, M;

vector <pair <int,int>> v[100001];

class node {
public:
	int value;
	int count;
	int hyperIndex;

	node(int value, int count, int hyperIndex) {
		this->value = value;
		this->count = count;
		this->hyperIndex = hyperIndex;
	}
};

int BFS(int i) {
	bool check[100001] = { false, };

	check[i] = true;
	
	queue <node> q;

	q.push(node(i, 1, -1));

	while (q.size()) {
		node front = q.front();
		q.pop();

		if (front.value == N)
			return front.count;

		for (int j = 0; j < v[front.value].size(); j++) {
			if (check[v[front.value][j].first] == false) {
				check[v[front.value][j].first] = true;
				
				if (v[front.value][j].second != front.hyperIndex) {
					q.push(node(v[front.value][j].first, front.count + 1, v[front.value][j].second));
				}
				else {
					q.push(node(v[front.value][j].first, front.count, v[front.value][j].second));
				}
			}
		}

	}
	return -1;
}
int main() {

	cin >> N >> K >> M;
	int tmp;
	for (int i = 0; i < M; i++) {
		vector <int> input;
		for (int j = 0; j < K; j++) {
			scanf("%d", &tmp);
			input.push_back(tmp);
		}
		sort(input.begin(), input.end());
		for (int j = 1; j < K; j++) {
			v[input[0]].push_back(make_pair(input[j], i));
			v[input[j]].push_back(make_pair(input[0], i));
		}

	}

	cout << BFS(1);
	//system("Pause");

}