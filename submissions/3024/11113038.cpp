#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

char graph[31][31];
int N;
bool check[26];
bool tictactoe2(char player) {

	for (int i = 0; i < N; i++) {
		int f = 0;
		for (int j = 0; j < N; j++) {
			if (graph[j][i] != player) {
				f = 1;
				break;
			}
		}
		if (f == 0) {
			return true;
		}
	}


	for (int i = 0; i < N; i++) {
		int f = 0;
		for (int j =0 ; j < N; j++) {
			if (graph[i][j] != player) {
				f = 1;
				break;
			}
		}
		if (f == 0) {
			return true;
		}
	}

	int f = 0;
	for (int i = 0; i < N; i++) {

		if (graph[0 + i][0 + i] != player) {
			f = 1;
			break;
		}

	}
	if (f == 0) {
		return true;
	}
	f = 0;
	for (int i = 0; i < N; i++) {
		if (graph[0 + i][N-1 - i] != player) {
			f = 1;
			break;
		}



	}

	if (f == 0) {
		return true;
	}

	return false;

}


int main() {
	scanf("%d", &N);


	
	char dd;

	for (int i = 0; i < N; i++) {
		scanf("%1c", &dd);
		for (int j = 0; j < N; j++) {
		
			scanf("%1c", &graph[i][j]);
			
			check[graph[i][j] - 'A'] = true;
		}
	
	}






	int f = 0;
	for (int i = 0; i < 26; i++) {


		if (check[i] == true) {
			if (tictactoe2(i + 'A') == true) {
				printf("%c", i + 'A');
				f = 1;
				break;
			}

		}
	}
	if (f == 0) {
		cout << "ongoing";
	}

}