#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

queue <int> q;
bool check[100001];
int N, K;

void ch(int x) {
	if (check[x] == false) {
		q.push(x);
		check[x] = true;
	}
}
int BFS(int x) {
	q.push(x);
	check[x] = true;
	int level = 0;
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int x1 = q.front();
			
			q.pop();
			if (x1 == K)
				return level;
			if (x1+1 <=100000)
			ch(x1 + 1);
			if (x1-1 >=0)
			ch(x1 - 1);
			if (2*x1 <=100000)
			ch(2 * x1);
		}

		level++;

	}


}
int main() {
	cin >> N >> K;


	cout << BFS(N);
	
}