#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N1[41];
int N, S;

vector <int> v;

int result = 0;

vector <int> front;
vector <int> back;

bool calculate(string frontorback) {
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		result += N1[v[i]];
	}
	if (frontorback == "front") {
		front.push_back(result);
	}
	else {
		back.push_back(result);
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
	sort(back.begin(), back.end());

	int fronti = 0;
	int backi = back.size() - 1;
	if (front.size() == 0 || back.size() == S) {

	}
	else {
		while (1) {
			if (front[fronti] + back[backi] == S) {
				result++;
				fronti++;
				if (fronti >= front.size())
					break;
			}
			else if (front[fronti] + back[backi] < S) {
				fronti++;
				if (fronti >= front.size())
					break;
			}
			else {
				backi--;
				if (backi <= -1)
					break;
			}
		}
	}
	cout << result;
	//system("Pause");
}