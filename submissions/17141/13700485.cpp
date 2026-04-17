#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;

int lab[51][51];
vector < pair <int, int>> v;

vector <int> virus;

int N, M;
bool check[51][51];

int result = -1;

int dir[4][2] = { {-1,0},{1,0}, {0,-1},{0,1} };

int i1, i2, i3, i4;

int tmplab[51][51];
int contagious(int lab[][51]) {
	queue <pair <int, int>> q;

	for (int i = 0; i < virus.size(); i++) {
		q.push(make_pair(v[virus[i]].first, v[virus[i]].second));
		check[v[virus[i]].first][v[virus[i]].second] = true;
	}
	
	int time = 0;
	while (!q.empty()) {
		int size = q.size();
		bool flag = false;
		for (int i = 0; i < size; i++) {
			int fronti = q.front().first;
			int frontj = q.front().second;
			
			q.pop();

			for (int i = 0; i < 4; i++) {
				int tmpi = fronti + dir[i][0];
				int tmpj = frontj + dir[i][1];
				if (tmpi < 0 || tmpj < 0 || tmpi >= N || tmpj >= N)
					continue;
				if (check[tmpi][tmpj] == false && lab[tmpi][tmpj] != 1) {
					q.push(make_pair(tmpi, tmpj));
					check[tmpi][tmpj] = true;
					flag = true;
				
				}
			}
		}
		if (flag == false)
			return time;
		else 
			time++;
	}
	return time;

}

int viruscheck() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (lab[i][j] == 0 && check[i][j] == false) {
				return false;
			}
		}
	}
	return true;
}

void recursion(int i) {
	if (virus.size() == M) {
		memset(check, false, sizeof(check));
		
		memcpy(tmplab, lab, sizeof(lab));
		int dd = contagious(lab);
		memcpy(lab, tmplab, sizeof(lab));


		if (viruscheck()) {
			if (result == -1) {
				result = dd;
			}
			else {
				result = min(result, dd);
			}
		}
			
		virus.pop_back();
		return;
	}
	for (int i1 = i; i1 < v.size(); i1++) {
		virus.push_back(i1);
		recursion(i1 + 1);
	}
	if (virus.size() >= 1)
		virus.pop_back();
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &lab[i][j]);
			if (lab[i][j] == 2) {
				v.push_back(make_pair(i, j));
			}
		}
	}


	recursion(0);

	cout << result;
	//system("Pause");
}