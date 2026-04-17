#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

char graph[13][7];

int dir[4][2] = { {-1, 0}, {1, 0} ,{0 , -1}, {0, 1} };

bool check[13][7];

int totalcount;

void DFS(int i, int j, char Buyo, int count) {
	bool flag = false;
	for (int i1 = 0; i1 < 4; i1++) {
		int ni = i + dir[i1][0];
		int nj = j + dir[i1][1];
		if (ni < 0 || nj < 0 || ni >= 12 || nj >= 6)
			continue;
		
		if (graph[ni][nj] == Buyo && check[ni][nj] == false) {
			check[ni][nj] = true;
			flag = true;
			totalcount++;
			DFS(ni, nj, Buyo, count + 1);
			if (totalcount >= 4) {
				graph[ni][nj] = '.';
				return;
			}
		}
	
	}
	if (flag == false) {
		return;
	}
}


int main() {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> graph[i][j];
		}
	}
	int answer = 0;
	
	while (1) {
		memset(check, false, sizeof(check));
		bool flag = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				
				if (check[i][j] == false && graph[i][j] != '.') {
					check[i][j] = true;
					totalcount = 1;
					DFS(i, j, graph[i][j], 1);
					if (totalcount >= 4) {
						graph[i][j] = '.';
						flag = true;
					}
				}
			}
		}
	
		for (int j = 0; j < 6; j++) {
			vector <char> v;
			for (int i = 11; i >= 0; i--) {
				if (graph[i][j] != '.') {
					v.push_back(graph[i][j]);
					graph[i][j] = '.';
				}
			}
			for (int i = 0; i < v.size(); i++) {
				graph[ 11- i][j] = v[i];
			}
		}
		if (flag == false) {
			cout << answer;
			break;
		}
		answer++;
	}
	//system("Pause");
}