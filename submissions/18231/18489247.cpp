#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector <int> graph[2001];

bool firedCity[2001];

vector <int> result;

int N, M;

void checkAndPush(int index) {
	if (firedCity[index] == false)
		return;
	for (int i = 0; i < graph[index].size(); i++) {
		if (firedCity[graph[index][i]] == false)
			return;
	}
	result.push_back(index);
}


bool checkIfAnswer() {
	for (int i = 0; i < result.size(); i++) {
		firedCity[result[i]] = false;
		for (int j = 0; j < graph[result[i]].size(); j++) {
			firedCity[graph[result[i]][j]] = false;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (firedCity[i] == true)
			return false;
	}
	return true;
}

int main() {

	cin >> N >> M;

	int U, V;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &U, &V);
		graph[U].push_back(V);
		graph[V].push_back(U);
	}

	int K;
	cin >> K;
	int P;

	for (int i = 0; i < K; i++) {
		scanf("%d", &P);
		firedCity[P] = true;
	}

	for (int i = 1; i <= N; i++) {
		checkAndPush(i);
	}

	if (result.size() ==0 || !checkIfAnswer()) {
		cout << -1;
	}
	else {
		cout << result.size() << endl;
		for (int i = 0; i < result.size(); i++) {
			printf("%d ", result[i]);
		}
	}

	//system("Pause");
}