#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int N;

queue <int> q;
void push(int n) {
	q.push(n);
}

int front() {
	if (q.empty() != 1)
		return q.front();
	else
		return -1;
}

int back() {
	if (q.empty() != 1)
		return q.back();
	else
		return -1;
}

int size() {
	return q.size();
}

int pop() {

	if (q.empty() != 1) {
	int b = q.front();
	q.pop();
	return b;
}
	else
		return -1;
}


int empty() {
	
	return q.empty();
}



int main() {
	cin >> N;

	string N1[20000];
	string tmp="";
	getline(cin, tmp);
	N1[0] = tmp;


	for (int i = 0; i < N; i++) {
		getline(cin, tmp);
		N1[i] = tmp;

	}
	

	for (int i = 0; i < N; i++) {
		if (N1[i].at(0) == 'p' && N1[i].at(1) == 'u') {
			N1[i].erase(0, 5);
			push(stoi(N1[i]));
		}

		else if (N1[i] == "pop")
			printf("%d\n", pop());
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