#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char graph[11][11];
pair <int, int> R1;
pair <int, int> B1;
pair <int, int> R;
pair <int, int> B;

int f = 0;
vector < int> v;
int N, M;
queue <pair < pair <int, int>  , char> > q;

int RB( pair <int, int> tmp, char tmp2) {
	
	if (tmp2 == 'R') {
		if (tmp.first == B.first && tmp.second == B.second)
			return 0;
		else {
			R = tmp;
			return 1;
		}

		
	}

	else {
		if (tmp.first == R.first && tmp.second == R.second)
			return 0;
		else {
			B = tmp;
			return 1;
		}

	}

}
int BFS0() {
	int cc = 0;
	if (R.second < B.second) {
		q.push(make_pair(R, 'R'));
		q.push(make_pair(B, 'B'));
	}

	else {
		q.push(make_pair(B, 'B'));
		q.push(make_pair(R, 'R'));
	}
	while (!q.empty()) {
		pair <int, int > tmp = q.front().first;
		char tmp2 = q.front().second;
		q.pop();
		if (graph[tmp.first][tmp.second] == 'O') {
			if (tmp2 == 'R')
				cc = 1;
			else
				cc= -1;
		}
		else if (tmp.second-1 >= 0 && graph[tmp.first][tmp.second-1] != '#') {
			tmp.second = tmp.second - 1;
			if (RB(tmp, tmp2))
			q.push(make_pair(tmp, tmp2));
		}

	}

	return cc;
}
int BFS1() {
	int cc = 0;
	if (R.second > B.second) {
		q.push(make_pair(R, 'R'));
		q.push(make_pair(B, 'B'));
	}

	else {
		q.push(make_pair(B, 'B'));
		q.push(make_pair(R, 'R'));
	}
	while (!q.empty()) {
		pair <int, int > tmp = q.front().first;
		char tmp2 = q.front().second;
		q.pop();
		if (graph[tmp.first][tmp.second] == 'O') {
			if (tmp2 == 'R')
				cc = 1;
			else
				cc= -1;
		}
		else if (tmp.second + 1 < M && graph[tmp.first][tmp.second+1] != '#') {
			tmp.second = tmp.second + 1;
			if (RB(tmp, tmp2))
			q.push(make_pair(tmp, tmp2));
		}

	}

	return cc;
}

int BFS2() {
	int cc = 0;
	if (R.first < B.first) {
		q.push(make_pair(R, 'R'));
		q.push(make_pair(B, 'B'));
	}

	else {
		q.push(make_pair(B, 'B'));
		q.push(make_pair(R, 'R'));
	}
	while (!q.empty()) {
		pair <int, int > tmp = q.front().first;
		char tmp2 = q.front().second;
		q.pop();
		if (graph[tmp.first][tmp.second] == 'O') {
			if (tmp2 == 'R')
				cc = 1;
			else
				cc= -1;
		}
		else if (tmp.first - 1 >= 0 && graph[tmp.first - 1][tmp.second] != '#') {
			tmp.first = tmp.first - 1;
			if (RB(tmp, tmp2))
			q.push(make_pair(tmp, tmp2));
		}

	}

	return cc;
}
int BFS3() {
	int cc = 0;
	if (R.first > B.first) {
		q.push(make_pair(R, 'R'));
		q.push(make_pair(B, 'B'));
	}

	else {
		q.push(make_pair(B, 'B'));
		q.push(make_pair(R, 'R'));
	}
	while (!q.empty()) {
		pair <int, int > tmp = q.front().first;
		char tmp2 = q.front().second;
		q.pop();
		if (graph[tmp.first][tmp.second] == 'O') {
			if (tmp2== 'R')
				cc= 1;
			else
				cc= -1;
		}
		else if (tmp.first + 1 < N && graph[tmp.first + 1][tmp.second] != '#') {
			tmp.first = tmp.first + 1;
			if (RB(tmp, tmp2))
			q.push(make_pair(tmp, tmp2));
		}

	}

	return cc;
}
int recursion(int count) {
	if (count == 0) {
		for (int i = 0; i < v.size(); i++) {
			int result;
			if (v[i] == 0)
				result = BFS0();
			else if (v[i] == 1)
				result = BFS1();
			else if (v[i] == 2)
				result = BFS2();
			else if (v[i] == 3)
				result = BFS3();
			
			if (result == 1) {
					
				f = 1;
				v.pop_back();
				R = R1;
				B = B1;
				return 1;
			}
			else if (result == -1) {
				v.pop_back();
				R = R1;
				B = B1;
				return -1;
			}

		}
		R = R1;
		B = B1;
		v.pop_back();
		return 0;
	}

	v.push_back(0);
	recursion(count - 1);
	
		
	v.push_back(1);
	
	recursion(count - 1);
	

	
	v.push_back(2);
	recursion(count - 1);
	
	v.push_back(3);
	
	recursion(count - 1);
	
	
	if (v.size() >= 1)
		v.pop_back();


}


int main() {
	
	cin >> N >> M;




	char tmp;



	for (int i = 0; i < N; i++) {
		scanf("%1c", &tmp);
		for (int j = 0; j < M; j++) {
			scanf("%1c", &graph[i][j]);
			if (graph[i][j] == 'R') {
				R1.first = i;
				R1.second = j;
			}
			else if (graph[i][j] == 'B') {
				B1.first = i;
				B1.second = j;
			}


		}

	}

	R = R1;
	B = B1;



	recursion(10);

	cout << f;
	

}