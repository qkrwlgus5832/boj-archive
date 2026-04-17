#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <char> v;
char direction[4] = { 'L', 'R', 'D', 'U' };

long long board[21][21];


int N;

long long result = 0;

void backset(int backboard[][21]) {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			backboard[i][j] = board[i][j];
		}
	}
}
void boardset(int backboard[][21]) {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			board[i][j] = backboard[i][j];
		}
	}
}

void setcolzero(int i) {
	for (int i1 = 0; i1 < 21; i1++)
		board[i][i1] = 0;
}

void setrowzero(int j) {
	for (int i1 = 0; i1 < 21; i1++)
		board[i1][j] = 0;
}


void recursion(char direction, int count) {
	if (count == 5)
		return;

	count++;

	

	int backboard[21][21];
	//for (int i = 0; i < 21; i++) {
	//	/*memcpy(backboard[i], board[i], sizeof(board[i]));*/
	//	for (int j = 0; j < 21; j++) {
	//		backboard[i][j] = board[i][j];
	//	}
	//}
	

	if (direction == 'L') {
		for (int i = 0; i < N; i++) {
			vector <pair<int,bool>> v2;
			for (int j = 0; j < N; j++) {
				if (board[i][j] != 0) {
					if (v2.size() >= 1 && v2.back().second != true && v2.back().first == board[i][j]) {
							v2.pop_back();
							v2.push_back(make_pair(board[i][j] * 2, true));

					}
					else {
						v2.push_back(make_pair(board[i][j], false));
					}
				}
			}
			setcolzero(i);

			for (int i1 = 0; i1 < v2.size(); i1++) {
				board[i][i1] = v2[i1].first;
				result = max(result, board[i][i1]);
			}
		}
	}
	else if (direction == 'R') {
		for (int i = 0; i < N; i++) {
			vector <pair<int, bool>> v2;
			for (int j = N-1; j >= 0; j--) {
				if (board[i][j] != 0) {
					if (v2.size() >= 1 && v2.back().second != true && v2.back().first == board[i][j]) {
						v2.pop_back();
						v2.push_back(make_pair(board[i][j] * 2, true));

					}
					else {
						v2.push_back(make_pair(board[i][j], false));
					}
				}
				
			}
			setcolzero(i);

			for (int i1 = 0; i1 < v2.size(); i1++) {
				board[i][N-1-i1] = v2[i1].first;
				result = max(result, board[i][N - 1 - i1]);
			}
		
		}
	}
	else if (direction == 'U') {
		for (int j = 0; j < N; j++) {
			vector <pair<int, bool>> v2;
			for (int i = 0; i < N; i++) {
				if (board[i][j] != 0) {
					if (v2.size() >= 1 && v2.back().second != true && v2.back().first == board[i][j]) {
						v2.pop_back();
						v2.push_back(make_pair(board[i][j] * 2, true));

					}
					else {
						v2.push_back(make_pair(board[i][j], false));
					}
				}
		
			}
			setrowzero(j);

			for (int i1 = 0; i1 < v2.size(); i1++) {
				board[i1][j] = v2[i1].first;
				result = max(result, board[i1][j]);
			}
		}
	}
	else if (direction == 'D') {
		for (int j = 0; j < N; j++) {
			vector <pair<int, bool>> v2;
			for (int i = N-1; i >=0; i--) {
				if (board[i][j] != 0) {
					if (v2.size() >= 1 && v2.back().second != true && v2.back().first == board[i][j]) {
						v2.pop_back();
						v2.push_back(make_pair(board[i][j] * 2, true));

					}
					else {
						v2.push_back(make_pair(board[i][j], false));
					}
				}
		
			}
			setrowzero(j);

			for (int i1 = 0; i1 < v2.size(); i1++) {
				board[N - 1 - i1][j] = v2[i1].first;
				result = max(result, board[N - 1 - i1][j]);
			}
		}
	}
	

	backset(backboard);

	recursion('L',  count);
	boardset(backboard);
	recursion('R', count);
	boardset(backboard);
	recursion('U', count);
	boardset(backboard);
	//recursion('R', count);
	//boardset();

	recursion('D',  count);

	boardset(backboard);
	//for (int i = 0; i < 21; i++) {
	//	for (int j = 0; j < 21; j++) {
	//		board[i][j] = backboard[i][j];
	//	}
	//}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	recursion('O', -1);

	cout << result;
	//system("Pause");
}