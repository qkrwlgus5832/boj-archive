#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <deque>
#include <string>
#include <cstring>
using namespace std;

int N;

deque <int> q;
void push_front(int n) {
	q.push_front(n);
}



void push_back(int n) {
	q.push_back(n);
}


int pop_front() {
	if (q.empty() != 1) {
		int a = q.front();
		q.pop_front();
		return a;
	}

	else
		return -1;
}

int pop_back() {
	if (q.empty() != 1) {
		int a = q.back();
		q.pop_back();
		return a;
	}
	else
		return -1;
}

int size() {
	return q.size();
}


int empty() {

	return q.empty();
}

int front() {
	if (!q.empty()) {
		return q.front();
	}
	else
		return -1;

}
int back() {
	if (!q.empty()) {
		return q.back();
	}
	else
		return -1;

}
int main() {
	
	cin >> N;



	string N1[20000];
	string tmp = "";
	getline(cin, tmp);
	N1[0] = tmp;


	for (int i = 0; i < N; i++) {
		getline(cin, tmp);
		N1[i] = tmp;

	}


	for (int i = 0; i < N; i++) {
		if (N1[i].at(0) == 'p' && N1[i].at(1) == 'u') {
			if (N1[i].at(5) == 'f') {
				N1[i].erase(0, 11);
				push_front(stoi(N1[i]));
			}
			else if (N1[i].at(5) == 'b') {
				N1[i].erase(0, 10);
				push_back(stoi(N1[i]));
			}

		}

		else if (N1[i] == "pop_front")
			printf("%d\n", pop_front());
		else if (N1[i] == "pop_back")
			printf("%d\n", pop_back());
		else if (N1[i] == "size")
			printf("%d\n", size());
		else if (N1[i] == "empty")
			printf("%d\n", empty());
		else if (N1[i] == "front")
			printf("%d\n", front());
		else if (N1[i] == "back")
			printf("%d\n", back());
	}


}