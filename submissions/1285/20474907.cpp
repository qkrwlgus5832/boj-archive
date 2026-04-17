#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <limits.h>

using namespace std;

char graph[21][21];
int N;
int result = INT_MAX;

void reverseRow(int index) { // 행에 대해서 reverse해주는 함수
	for (int j = 0; j < N; j++) {
		if (graph[index][j] == 'H')
			graph[index][j] = 'T';
		else
			graph[index][j] = 'H';
	}
}

void reverseCol(int index, char tmpgraph[21][21]) { // 열에 대해서 reverse해주는 함수
	for (int i = 0; i < N; i++) {
		if (tmpgraph[i][index] == 'H')
			tmpgraph[i][index] = 'T';
		else
			tmpgraph[i][index] = 'H';
	}
}

int getCount(char tmpgraph[21][21]) { // T개수 count함수
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tmpgraph[i][j] == 'T')
				count++;
		}
	}
	return count;
}

int greedy() {
	char tmpgraph[21][21]; // tmpgraph 복사 배열을 만듬

	memcpy(tmpgraph, graph, sizeof(graph));

	for (int j = 0; j < N; j++) { // 각 열을 돌면서 
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (tmpgraph[i][j] == 'T') {
				count++;
			}
		}
		if (count * 2 > N) { //T 개수가 H개수보다 많다면 
			reverseCol(j, tmpgraph); // 그 열을 뒤집어준다.
		}
	}
	return getCount(tmpgraph);
}


void recursion(int index) {
	result = min(result, greedy()); // 열에 대한 greedy
	for (int i = index; i < N; i++) { // 행을 무작위로 고르면서 뒤집어준다.
		reverseRow(i);
		recursion(i + 1);
		reverseRow(i);
	}
}
int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {

		scanf("%s", graph[i]);

	}

	recursion(0);
	cout << result;
	//system("Pause");
}