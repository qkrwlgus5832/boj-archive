#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int cycle[101];
vector <int> graph[101];


bool flag = false;

void DFS(int x) {
	if (cycle[x] == 1) {
		cout << "CYCLE";
		exit(0);
	}
	cycle[x] = 1;


	for (auto i : graph[x]) {
		if (cycle[i] != 2) DFS(i);
	}
	cycle[x] = 2;
}

int main() {
	int N;
	cin >> N;

	int count;
	int number;
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d", &count);
		for (int j = 0; j < count; j++) {
			scanf("%d", &number);
			graph[i].push_back(number);
		}
	}
	
	DFS(1);

	cout << "NO CYCLE";
	//system("Pause");

}