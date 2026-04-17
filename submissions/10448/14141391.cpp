#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int trianglenumber[1000];


int BFS(int x) {
	//bool check[46][46][46] = { false };
	queue <pair <int, int>> q;
	for (int i = 1; i <= 45; i++) {
		if (trianglenumber[i] <= x)
			q.push(make_pair(trianglenumber[i], 1));
		else
			break;
	}

	while (!q.empty()) {
		int value = q.front().first;
		int count = q.front().second;
		q.pop();
		if (count == 3 && value == x) {
			return 1;
		}

		for (int i = 1; i <= 45; i++) {
			if (value + trianglenumber[i] <= x)
				q.push(make_pair(value + trianglenumber[i], count + 1));
			else
				break;
		}
	}
	return 0;
}
int main() {
	cin.tie(NULL);
	int i = 1;
	int number = 1;
	while (1) {
		trianglenumber[i] = number;
		i++;
		number += i;
		if (number > 1000)
			break;
	}
	int t;
	cin >> t;
	int K;

	for (int i = 0; i < t; i++) {
		cin >> K;
		printf("%d\n", BFS(K));
	}
	//system("Pause");
}