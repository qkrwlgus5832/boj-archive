#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <iostream>
#include <queue>
using namespace std;

queue <int> q;

int check[100001];
int N, K;

int mcount;

int result = 0;
void ch(int x, int level) {
	if (check[x] == level || check[x] == false) {
		q.push(x);
		check[x] = level;
	}
}
pair <int, int> BFS(int x) {
	q.push(x);
	check[x] = true;
	int f = 0;
	int count = 1;
	int level = 0;
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int x1 = q.front();

			q.pop();

			if (f == 1 && x1 == K) {
				count++;
			}
			else if (x1 == K) {
				f = 1;

			}
			if (x1 + 1 <= 100000)
				ch(x1 + 1, level);
			if (x1 - 1 >= 0)
				ch(x1 - 1, level);
			if (2 * x1 <= 100000)
				ch(2 * x1, level);
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


	cout << result.first << endl;
	cout << result.second;



}