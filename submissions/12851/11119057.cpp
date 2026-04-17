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
				ch(x1 + 1);
			if (x1 - 1 >= 0)
				ch(x1 - 1);
			if (2 * x1 <= 100000)
				ch(2 * x1);
		}
		if (f == 1) {
			return make_pair(level, count);
		}
		level++;

	}


}
int main() {
	cin >> N >> K;


	pair <int ,int> result = BFS(N);
	cout << result.first << endl;
	cout << result.second;

}