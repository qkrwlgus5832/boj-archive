#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;


int A[101][101];
int tmpA[101][101];
int r, c, k;

int rowcount = 3;
int colcount = 3;

bool cmp(pair <int, int> a, pair <int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else
		return a.second < b.second;
}

void vectorpush(vector <pair <int, int>> &v, int check[101]) {
	for (int i1 = 1; i1 <= 101; i1++) {
		if (check[i1] > 0) {
			v.push_back(make_pair(i1, check[i1]));
		}
	}
}
int R() {
	int col = 0;
	vector <pair <int,int>> v;
	int check[101] = { 0, };

	for (int i = 0; i < rowcount; i++) {
		for (int j = 0; j < colcount; j++) {
			if (tmpA[i][j] != 0) {
				check[tmpA[i][j]]++;
			}
		}

		vectorpush(v, check);
		sort(v.begin(), v.end(), cmp);
		
		for (int i1 = 0; i1 < v.size(); i1++) {
			A[i][i1 * 2] = v[i1].first;
			A[i][i1 * 2 + 1] = v[i1].second;
		}
		col = max((unsigned int)col, v.size() * 2);
		v.clear();
		memset(check, 0, sizeof(check));
	}
	return col;
}

int C() {
	int row = 0;
	vector <pair <int, int>> v;
	int check[101] = { 0, };

	for (int i = 0; i < colcount; i++) {
		for (int j = 0; j < rowcount; j++) {
			if (tmpA[j][i] != 0) {
				check[tmpA[j][i]]++;
			}
		}

		vectorpush(v, check);
		sort(v.begin(), v.end(), cmp);
		
		for (int i1 = 0; i1 < v.size(); i1++) {
			A[i1*2][i] = v[i1].first;
			A[i1*2+1][i] = v[i1].second;
		}
		row = max((unsigned int)row, v.size() * 2);
		v.clear();
		memset(check, 0, sizeof(check));
	}
	return row;
}

int main() {
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	int result = -1;
	for (int time = 0; time <= 100; time++) {
		if (A[r-1][c-1] == k) {
			result = time;
			break;
		}
		memcpy(tmpA, A, sizeof(A));

		memset(A, 0, sizeof(A));

		if (rowcount >= colcount) {
			colcount = R();
		}
		else {
			rowcount = C();
		}

	}
	cout << result;
	//system("Pause");
}