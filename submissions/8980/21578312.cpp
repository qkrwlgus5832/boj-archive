#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

class node{
public:
	int sender;
	int receiver;
	int count;

	node(int sender, int receiver, int count) {
		this->sender = sender;
		this->receiver = receiver;
		this->count = count;
	}
};

vector <node> v[2001];

struct compare {
	bool operator()(node &a, node &b) {
		return a.receiver > b.receiver;

	}
};
priority_queue <node, vector <node>, compare> q;


int main() {
	int N, C;
	cin >> N >> C;

	int M;
	cin >> M;

	int sender, receiver,  count;
	


	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &sender, &receiver, &count);
		v[sender].push_back(node(sender, receiver, count));
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end(), [](const node& a, const node& b) {
			return a.receiver < b.receiver;
		});

	}

	int sum = 0;
	int result = 0;

	for (int i = 1; i <= N; i++) {

		while (q.size()) { // 택배를 마을에 보내고
			node front = q.top();
			if (front.receiver == i) {
				sum -= front.count;
				result += front.count;
				q.pop();
			}
			else
				break;
		}

		for (int j = 0; j < v[i].size(); j++) { // 택배를 싣고
			node node_ = v[i][j];
			if (sum + node_.count <= C) {
				sum += node_.count;
				
				q.push(node(i, v[i][j].receiver, v[i][j].count));
			}
			else if (C - sum > 0){
				q.push(node(i, v[i][j].receiver, C - sum));
				sum = C;
			}

		}
	}
	cout << result;
	//system("Pause");
}
