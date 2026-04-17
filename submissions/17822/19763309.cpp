#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

deque <int> q[51];

int N, M, T;

void clock(int negaveIndex) {
	int tmp = q[negaveIndex].back();
	q[negaveIndex].pop_back();
	q[negaveIndex].push_front(tmp);
}

void anticlock(int negaveIndex) {
	int tmp = q[negaveIndex].front();
	q[negaveIndex].pop_front();
	q[negaveIndex].push_back(tmp);
}


void rotate(int negaveIndex,  int k, int d) {



	for (int i = 0; i < k; i++) {
		if (d == 0) {
			clock(negaveIndex);
		}
		else {
			anticlock(negaveIndex);
		}
	}

}

void check() {

	bool check[51][51] = { false, };
	bool flag = false;
	int value = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < q[i].size(); j++) {
			if (q[i][j] == 0)
				continue;
			if (i > 0 && q[i][j] == q[i - 1][j]) {
				check[i][j] = true; check[i - 1][j] = true;

			}
			if (i < N - 1 && q[i][j] == q[i + 1][j]) {
				check[i][j] = true; check[i + 1][j] = true;

			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int left = j - 1;
			int right = j + 1;

			if (j == 0) {
				left = q[i].size() - 1;
			}
			else if (j == q[i].size() - 1) {
				right = 0;
			}

			if (q[i][j] == 0)
				continue;
			if (q[i][j] == q[i][left]) {
				check[i][j] = true; check[i][left] = true;

			}

			if (q[i][j] == q[i][right]) {
				check[i][j] = true; check[i][right] = true;

			}
		}
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == true) {
				q[i][j] = 0;
				flag = true;
				
			}
			else if (q[i][j] !=0){
				value += q[i][j];
				count++;
			}
		}
	}

	if (count == 0) {
		return;
	}
	double avg = (double) value / count;
	if (flag == false) {
		for (int i1 = 0; i1 < N; i1++) {
			for (int j1 = 0; j1 < M; j1++) {
				if (q[i1][j1] == 0)
					continue;
				if ((double)q[i1][j1] > avg) {
					q[i1][j1]--;
				}
				else if ((double)q[i1][j1] < avg) {
					q[i1][j1]++;
				}
			}
		}

	}

}


int main() {


	cin >> N >> M >> T;

	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			q[i].push_back(tmp);
		}
	}

	int x, d, k;

	for (int i = 0; i < T; i++) {

		cin >> x >> d >> k;
		for (int j = x; j <= N; j+=x) {
			rotate(j -1, k, d);
		}
		

		check();



	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result += q[i][j];
		}
	}
	cout << result;

	//system("Pause");
}