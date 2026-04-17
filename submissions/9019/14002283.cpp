#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>

using namespace std;


deque <int> getdivde(int x) {
	deque <int> q;
	int d1 = x / 1000;
	int d2 = (x % 1000) / 100;
	int d3 = (x % 1000) % 100 / 10;
	int d4 = (x % 1000) % 100 % 10;
	q.push_back(d1);
	q.push_back(d2);
	q.push_back(d3);
	q.push_back(d4);
	return q;
}

int getcaculate(deque <int>& q) {
	int d1 = q[0];
	int d2 = q[1];
	int d3 = q[2];
	int d4 = q[3];
	return ((d1 * 10 + d2) * 10 + d3) * 10 + d4;
}

int D(int x) {
	return (2 * x) % 10000;
}

int S(int x) {
	if (x - 1 == -1)
		return 9999;
	else
		return x - 1;
}

int L(int x) {
	deque <int> tmp = getdivde(x);
	int dd = tmp.front();
	tmp.pop_front();
	tmp.push_back(dd);
	return getcaculate(tmp);
}

int R(int x) {
	deque <int> tmp = getdivde(x);
	int dd = tmp.back();
	tmp.pop_back();
	tmp.push_front(dd);
	return getcaculate(tmp);
}

bool checkIfAnswer(int dd , int B, string frontvector) {
	if (dd == B) {
		for (int i = 0; i < frontvector.size(); i++)
			printf("%c", frontvector[i]);
		return true;
	}
	else
		return false;
}
void BFS(int A, int B) {
	queue <pair<int, string>> q;
	bool check[10000] = { false, };
	string v = "";
	q.push(make_pair(A, v));
	check[A] = true;
	
	while (!q.empty()) {
		for (int i = 0; i < q.size(); i++) {
			int front = q.front().first;
			string frontvector = q.front().second;
		

			q.pop();
			int dd = D(front);
		
			if (check[dd] == false) {
				q.push(make_pair(dd, frontvector + 'D'));
				check[dd] = true;
				if (checkIfAnswer(dd, B, frontvector + 'D') == true)
					return;
			}
		
			dd = S(front);
		
			if (check[dd] == false) {
	
				q.push(make_pair(dd, frontvector + 'S'));
				check[dd] = true;
				if (checkIfAnswer(dd, B, frontvector + 'S') == true)
					return;
		
			}
		
			dd = L(front);
	
			if (check[dd] == false) {
			
				q.push(make_pair(dd, frontvector + 'L'));
				check[dd] = true;
				if (checkIfAnswer(dd, B, frontvector + 'L') == true)
					return;
		
			}
	
			dd = R(front);
	
			if (check[dd] == false) {
		
				q.push(make_pair(dd, frontvector + 'R'));
				check[dd] = true;
				if (checkIfAnswer(dd, B, frontvector+ 'R') == true)
					return;
			
			}
		}

	}

}

int main() {
	int T;
	int A, B;
	cin >> T;

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &A, &B);
		BFS(A, B);
		printf("\n");
	}

	//system("Pause");
}