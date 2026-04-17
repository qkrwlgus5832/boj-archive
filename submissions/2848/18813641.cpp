#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector <string> inputs;

vector <char> graph[27];
int depth[27];

bool check[27][27];

bool inputcheck[27];

void topologicalSort(int count) {
	queue <char> q;
	vector <int> result;

	for (int i = 0; i <= 'z' - 'a'; i++) {
		if (depth[i] == 0 && inputcheck[i] == true) {
			q.push(i + 'a');
		}
	}
	while (!q.empty()) {
		int s = q.size(); 

		if (s > 1) {
			printf("?");
			return;
		}
		int front = q.front();

		q.pop();

		result.push_back(front);

		for (int i = 0; i < graph[front - 'a'].size(); i++) {
			if (--depth[graph[front- 'a'][i] -'a']  == 0) {
				q.push(graph[front - 'a'][i]);
			}
		}
	}

	if (count != result.size())
		printf("!");
	else {
		for (int i = 0; i < result.size(); i++) {
			printf("%c", result[i]);
		}
	}
}
int main() {
	int N;
	cin >> N;

	string input;
	
	for (int i = 0; i < N; i++) {
		cin >> input;
		inputs.push_back(input);
	}

	for (int i = 0; i < N - 1; i++) {
		int length = min(inputs[i].size(), inputs[i + 1].size());
		bool flag = false;
		for (int j = 0; j < length; j++) {
			if (inputs[i][j] != inputs[i + 1][j]) {
				if (check[inputs[i + 1][j] - 'a'][inputs[i][j]-'a'] == true) {
					printf("!");
					return 0;
				}
				if (check[inputs[i][j] - 'a'][inputs[i + 1][j] - 'a'] == false) {
					check[inputs[i][j] - 'a'][inputs[i + 1][j] - 'a'] = true;
					graph[inputs[i][j] - 'a'].push_back(inputs[i + 1][j]);
					depth[inputs[i + 1][j] - 'a']++;
				}
				flag = true;
				break;
			}

		}
		if (flag == false && inputs[i].size() > inputs[i + 1].size()) {
			printf("!");
			return 0;
		}
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < inputs[i].size(); j++) {
			if (inputcheck[inputs[i][j] - 'a'] == false) {
				count++;
				inputcheck[inputs[i][j] - 'a' ] = true;
			}
		}
	}
	topologicalSort(count);
	//system("Pause");
}