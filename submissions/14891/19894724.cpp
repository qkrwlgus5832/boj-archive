#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

vector <deque <int>> q;

void clockwise(int number) {
	int tmp = q[number].back();
	q[number].pop_back();
	q[number].push_front(tmp);
}

void anticlockwise(int number) {
	int tmp = q[number].front();
	q[number].pop_front();
	q[number].push_back(tmp);
}

void rightrecursion(int number, int dir, int originnumber) {
	if (number + 1 >= 4)
		return;
	if (q[number + 1][6] == q[number][2]) {
		return;
	}

	dir *= -1;
	number++;
	rightrecursion(number, dir, originnumber);
	

	if (dir == -1) {
		anticlockwise(number);
	}
	else {
		clockwise(number);
	}

}

void leftrecursion(int number, int dir, int originnumber) {
	if (number - 1 < 0)
		return;
	if (q[number - 1][2] == q[number][6]) {
		return;
	}

	dir *= -1;
	number--;

	leftrecursion(number, dir, originnumber);
	if (dir == -1) {
		anticlockwise(number);
	}
	else {
		clockwise(number);
	}

}
int main() {
	int tmp;
	q.resize(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &tmp);
			q[i].push_back(tmp);
		}

	}
	int K;
	cin >> K;

	int number, dir;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &number, &dir);
		number--;
		rightrecursion(number, dir, number);
		leftrecursion(number, dir, number);
		if (dir == -1) {
			anticlockwise(number);
		}
		else {
			clockwise(number);
		}
		
	}
	int result = 0;
	 tmp = 1;
	for (int i = 0; i < 4; i++) {
		if (q[i][0] == 1) {
			result += tmp;
		
		}	tmp *= 2;
	}
	cout << result;
	//system("Pause");
}