#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int N1[51][51];

vector  <pair <pair <int, int>, int>> v;

int N, M, k;

bool check[7];
vector <int> v2;

int result = -1;

int dir[4][2] = { { 0, 1}, {1, 0}, {0 ,-1}, {-1, 0} };
int tmpN1[51][51];

void rotate(int r, int c, int s, int N1[51][51]) {
	for (int i = 0; i < s; i++) {
		int starti = r - s + i;
		int startj = c - s + i;
		int endi = r + s - i;
		int endj = c + s - i;
		
		int currenti = starti; 
		int currentj = startj;
		int dirindex = 0;
		int beforevalue = N1[starti][startj];

		while (1) {
			int ni = currenti + dir[dirindex][0];
			int nj= currentj +  dir[dirindex][1];
			if (ni > endi || nj > endj || ni < starti || nj < startj) {
				dirindex++;
	
				continue;
			}
			int tmpbeforevalue = N1[ni][nj];
			N1[ni][nj] = beforevalue;
			beforevalue = tmpbeforevalue;
			currenti = ni;
			currentj = nj;

			if (currenti == starti && currentj == startj)
				break;	
		}
	}
}
//
int getminvalue() {
	
	memcpy(tmpN1, N1, sizeof(N1));

	for (int i = 0; i < v2.size(); i++) {
		rotate(v[v2[i]].first.first, v[v2[i]].first.second, v[v2[i]].second,  tmpN1);
	}
	int tmp = INT_MAX;

	for (int i = 0; i < N; i++) {
		int count = 0;
		for (int j = 0; j < M; j++) {
			count += tmpN1[i][j];
		}
		tmp = min(tmp, count);
	}

	return tmp;
}

void setcalculate() {
	do {
		if (result == -1) {
			result = getminvalue();
		}
		else				
			result = min(result, getminvalue());
			
	} while( next_permutation(v2.begin(), v2.end()));
}


int main() {
	cin >> N >> M >> k;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> N1[i][j];
		}
	}


	int r, c, s;
	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s;
		v.push_back(make_pair(make_pair(--r, --c), s));
	}

	for (int i = 0; i < k; i++) {
		v2.push_back(i);
	}
	setcalculate();

	cout << result;
	//system("Pause");
}