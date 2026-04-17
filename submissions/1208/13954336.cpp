#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int N1[41];
int N, S;

vector <int> v;

int result = 0;


//ap <int, int> front;
vector <int> front;
map <int, int> back;

bool calculate(string frontorback) {
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		result += N1[v[i]];
	}
	if (frontorback == "front") {
		front.push_back(result);
	}
	else {
		if (back.find(result) == back.end()) {
			back[result] = 1;
		}
		else {
			back[result]++;
		}
	}

	if (result == S) {
		return true;
	}
	else
		return false;
}

void frontrecursion(int i1, int N) {
	if (i1 != 0 && calculate("front") == true) {
		result++;
	}
	for (int i = i1; i < N ; i++) {
		v.push_back(i);
		frontrecursion(i + 1, N);
	}
	if (v.size() >= 1)
		v.pop_back();
}

void backrecursion(int i1, int N) {
	if (i1 != N / 2 && calculate("back") == true) {
		result++;
	}
	for (int i = i1; i < N; i++) {
		v.push_back(i);
		backrecursion(i + 1, N);
	}
	if (v.size() >= 1)
		v.pop_back();
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		scanf("%d", &N1[i]);
	}

	frontrecursion(0, N/2);
	
	backrecursion(N / 2, N);

	sort(front.begin(), front.end());
	//sort(back.begin(), back.end());


	if (front.size() == 0 || back.size() == 0) {

	}
	else {
		for (int i = 0; i < front.size(); i++) {
			if (back.find(S - front[i]) != back.end()) {
				result += (*back.find(S - front[i])).second;
			}
		}
	}

	cout << result;
	
	//system("Pause");
}