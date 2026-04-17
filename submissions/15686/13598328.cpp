#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector <pair <int, int>> chickenstore;

vector <pair <int, int>> pickedchickenstore;

vector <pair<int, int>> homelocation;

int graph[51][31];

int result = -1;

int getchickendistance() {
	int result = 0;
	for (int i = 0; i < homelocation.size(); i++) {
		int mindistance = -1;
		for (int j = 0; j < pickedchickenstore.size(); j++) {
			int distance = abs(homelocation[i].first - pickedchickenstore[j].first)
				+ abs(homelocation[i].second - pickedchickenstore[j].second);
			if (mindistance == -1)
				mindistance = distance;
			else
				mindistance = min(distance, mindistance);
		}
		result += mindistance;
	}
	return result;
}


void recursion(int count) {
	if (count == M) {
		if (result == -1)
			result = getchickendistance();
		else
			result = min(result,getchickendistance());

		pickedchickenstore.pop_back();
		return;
	}

	for (int i = count; i < chickenstore.size(); i++) {
		pickedchickenstore.push_back(chickenstore[i]);
		recursion(count + 1);
		//pickedchickenstore.pop_back();
	}
	if (pickedchickenstore.size() >= 1)
		pickedchickenstore.pop_back();
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 2)
				chickenstore.push_back(make_pair(i - 1, j - 1));
			else if (graph[i][j] == 1)
				homelocation.push_back(make_pair(i - 1, j - 1));
		}
	}

	recursion(0);
	cout << result;
	//system("Pause");
}