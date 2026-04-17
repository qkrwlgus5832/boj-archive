#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int check[500001][2];


void BFS(int N) {
	queue <int> q;
	q.push(N);

	check[N][0] = 0;

	int length = 1;

	while (q.size()) {
		int s = q.size();

		for (int qs = 0; qs < s; qs++) {
			int front = q.front();
			q.pop();


			if (front + 1 <= 500000 && check[front + 1][length % 2] == -1) {
				check[front + 1][length  %2] = length;
				q.push(front + 1);
			}
			if (front - 1 >= 0 && check[front - 1][length % 2] == -1) {
				check[front - 1][length% 2] = length;
				q.push(front - 1);
			}
			if (2 * front <= 500000 && check[2 * front][length % 2] == -1) {
				check[2 * front][length % 2] = length ;
				q.push(2 * front);
			}


		}
		length++;
	}

}
int main() {

		int N, K;

		cin >> N >> K;

		memset(check, -1, sizeof(check));

		BFS(N);

	

		int count = 0;
		bool flag = false;

		for (int i = K; i <= 500000; i += count) {

			if (check[i][count % 2] != -1 && check[i][count % 2] <= count) {
				flag = true;
				break;
			}
			count++;
		}
		if (flag)
			cout << count;
		else
			cout << -1;
	
	//system("Pause");
}
