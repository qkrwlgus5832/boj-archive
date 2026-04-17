#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory.h>

using namespace std;

vector <char> v;
char direction[4] = { 'L', 'R', 'D', 'U' };

long long board[21][21];


int N;

long long result = 0;


void setcolzero(int i) {
	for (int i1 = 0; i1 < 21; i1++)
		board[i][i1] = 0;
}

void setrowzero(int j) {
	for (int i1 = 0; i1 < 21; i1++)
		board[i1][j] = 0;
}


void super2048(string direction) {
	if (direction == "left") {
		for (int i = 0; i < N; i++) {
			vector <pair<int, bool>> v2;
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

			}
		}
	}
	else if (direction == "right") {
		for (int i = 0; i < N; i++) {
			vector <pair<int, bool>> v2;
			for (int j = N - 1; j >= 0; j--) {
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
				board[i][N - 1 - i1] = v2[i1].first;
		
			}

		}
	}
	else if (direction == "up") {
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
	
			}
		}
	}
	else if (direction == "down") {
		for (int j = 0; j < N; j++) {
			vector <pair<int, bool>> v2;
			for (int i = N - 1; i >= 0; i--) {
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
		
			}
		}
	}





}

int main() {

	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		string input;
		getline(cin, input);
		getline(cin, input);
		int pos = input.find(" ");
		N = atoi(input.substr(0, pos).c_str());
		string direction = input.substr(pos + 1, input.length() - pos);

		for (int i = 0; i < sizeof(board) / sizeof(board[0]); i++) {
			memset(board[i], 0, sizeof(board[i]));
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &board[i][j]);
			}
		}

		super2048(direction);
		printf("Case #%d:\n", i);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", board[i][j]);
			}
			printf("\n");
		}
	}

	//system("Pause");
}