#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <iostream>
#include <queue>
using namespace std;

queue <pair <int, int>> q;

int check[100001];
int N, K;

int mcount;
int time;
int result = 0;
void ch(int x, int level ,int flag, int y1) {
	if (check[x] == level || check[x] == false) {
		if (flag == 1)
			q.push(make_pair(x, y1+0));
		else
			q.push(make_pair(x, y1+1));
		check[x] = level;
	}

}
pair <int, int> BFS(int x) {
	q.push(make_pair(x,0));
	check[x] = true;
	int f = 0;
	int count = 1;
	int level = 0;
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int x1 = q.front().first;
			int y1 = q.front().second;
			q.pop();

			if (f == 1 && x1 == K) {
				count++;
				time = min(time, y1);
			}
			else if (x1 == K) {
				f = 1;
				time = y1;

			}
			if (x1 + 1 <= 100000) {
				ch(x1 + 1, level, false, y1);
			}

			if (x1 - 1 >= 0)
				ch(x1 - 1, level, false, y1);
			if (2 * x1 <= 100000)
				ch(2 * x1, level, true, y1);
		}
		if (f == 1) {
			return make_pair(level, count);
		}
		level++;

	}


}



int main() {
	cin >> N >> K;




	pair <int, int> result = BFS(N);


	cout << time;
	

}