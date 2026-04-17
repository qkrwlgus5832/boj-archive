#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;


vector <pair<int ,pair<short, short>>> v;

bool can[10001][10001];

bool check[10001];
int start, finish;
int BFS(int a, int b, int x, int y) {
	memset(can, false, sizeof(can));
	memset(check, false, sizeof(check));
	queue <short> q;
	q.push(a);
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first >= v[(x + y) / 2].first) {
			can[v[i].second.first][v[i].second.second] = true;
			can[v[i].second.second][v[i].second.first] = true;
		}

	}

	while (!q.empty()) {
		int tmp = q.front();

		if (tmp == b) 
			return 1;
			

		q.pop();
		check[tmp] = true;
		for (int i = 1; i <= b; i++) {
			if (can[tmp][i] == true && check[i]==false)
				q.push(i);
		}

 }
	return 0;
}


/*
bool compare(const pair<int, pair<short, short>> &a, pair<int, pair<short, short>>& b) {
	return a.first > b.first;
}
*/

int binary_search(int x, int y ) {

	if (x + 1 == y) {
		if (BFS(start, finish, y, y) == 1)
			return y;
		else
			return x;
	}


	int result = BFS(start, finish, x, y);
	 if (BFS(start,finish, x, y) == 0) {
		 return binary_search(x, (x + y) / 2 -1 );

	}
	else if (BFS(start,finish, x, y) ==1) {
		return binary_search((x + y) / 2 , y);

	}


}
int main() {

	cin >> N >> M;
	int A, B, C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		if (A > B)
			swap(A, B);
		v.push_back(make_pair(C, make_pair(A, B)));
	}
	

	cin >> start >> finish;

	if (start > finish) {
		swap(start, finish);
	}
	
	sort(v.begin(), v.end());

	




	int result = binary_search(0,v.size()- 1);

	cout << v[result].first;

}