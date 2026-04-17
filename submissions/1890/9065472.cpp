#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[101][101];
queue <pair <int, int>> q;




long long BFS() {
	int count = 0;
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		int value = arr[x1][y1];
		q.pop();

		if (x1 == N - 1 && y1 == N - 1) {
			count = count + 1;
		}
		if (x1 + arr[x1][y1] <= N - 1 && arr[x1][y1] !=0 ) {
			q.push(make_pair(x1 + arr[x1][y1], y1));
		}
		if (y1 + arr[x1][y1] <= N - 1 && arr[x1][y1] !=0) {
			q.push(make_pair(x1, y1 + arr[x1][y1]));
		}
	}
	return count;
}
int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}




	q.push(make_pair(0, 0));

	cout << BFS();

}


