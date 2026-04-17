#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

char graph[31][31];
int N;
int check[26];
bool tictactoe2(char player) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j + 2 >= N)
				continue;
			if (graph[i][j] == player && graph[i][j + 1] == player && graph[i][j + 2] == player)
				return true;
		}

	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i + 2 >= N)
				continue;
			if (graph[i][j] == player && graph[i+1][j] == player && graph[i+2][j] == player)
				return true;
		}

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i + 2 >= N || j + 2 >= N)
				continue;
			if (graph[i][j] == player && graph[i + 1][j + 1] == player && graph[i + 2][j + 2] == player)
				return true;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i -2<0 || j -2 <0)
				continue;
			if (graph[i][j] == player && graph[i -1][j - 1] == player && graph[i - 2][j - 2] == player)
				return true;
		}
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
			
			check[graph[i][j] - 'A']++;
		}
	
	}






	int f = 0;
	int max1 = -1;
	int maxi = -1;
	for (int i = 0; i < 26; i++) {



		if (check[i] >=1) {
			if (tictactoe2(i + 'A') == true) {
				f = 1;
				if (max1 == -1 && maxi == -1) {
					max1 = check[i];
					maxi = i;
				}
				if (check[i] > max1) {
					max1 = check[i];
					maxi = i;
				}
			}

		}
	}
	if (f == 1) {
		printf("%c", maxi + 'A');
	}
	if (f == 0) {
		cout << "ongoing";
	}

}