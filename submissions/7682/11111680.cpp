#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


char tictactoe[3][3];

vector <string> v;



bool tictactoe2(char player, string dd) {

	for (int i = 0; i < 3; i++) {
		int f = 0;
		for (int j =0; j < 3; j++) {
			if (dd.at(3*j+i) != player) {
				f = 1;
				break;
			}
		}
		if (f == 0) {
			return true;
		}
	}


	for (int i = 0; i < 3; i++) {
		int f = 0;
		for (int j =0; j < 3; j++) {
			if (dd.at(i*3+j) != player) {
				f = 1;
				break;
			}
		}
		if (f == 0) {
			return true;
		}
	}

	int f = 0;
	for (int i = 0; i < 3; i++) {

		if (dd.at((0 + i )*3 + 0 + i) != player) {
			f = 1;
			break;
		}

	}
	if (f == 0) {
		return true;
	}
	f = 0;
	for (int i = 0; i < 3; i++) {
		if (dd.at((0 + i) *3 + 2 - i) != player) {
			f = 1;
			break;
		}



	}

	if (f == 0) {
		return true;
	}

	return false;
}


int binary_search(int x, int y, string xx) {
	if (x == y) {
		if (v[x] == xx)
			return true;
		else
			return false;
	}
	else if (x + 1 == y) {
		if (v[x] == xx)
			return true;
		else if (v[y] == xx)
			return true;
		else
			return false;
	}
	else if (v[(x + y) / 2] <= xx) {
		return binary_search((x + y) / 2, y, xx);
	}
	else
		return binary_search(x, (x+y)/2 -1, xx);
}




void recursion(int count, char player, string dd) {
	char nplayer;
	if (player == 'O') {
		nplayer = 'X';

	}
	else {
		nplayer = 'O';
	}
	if (count == 9) {
		v.push_back(dd);
		return;
	}

	if (tictactoe2(nplayer, dd) == true) {
		v.push_back(dd);
		return;
	}



	for (int i = 0; i < dd.size(); i++) {
		if (dd.at(i) == '.') {
			dd.at(i) = player;
			recursion(count + 1, nplayer, dd);
			dd.at(i) = '.';
		}
	}




}

int main() {
	char a[100];
	char tt[3][3];



	recursion(0, 'X', ".........");
	sort(v.begin(), v.end());




	while (1) {


		memset(tt, '.', sizeof(tt));
		scanf("%s", a);
		string a1 = a;

		if (a1 == "end") {
			break;
		}

		if (binary_search(0, v.size() - 1, a1) == true)
			printf("valid\n");
		else
			printf("invalid\n");


	}



}