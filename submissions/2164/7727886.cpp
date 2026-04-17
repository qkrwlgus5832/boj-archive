#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int N;
int M;

deque <int> q;

int tmp;
int rotate() {
	while (1) {
		q.pop_front();
		if (q.size() == 1)
			break;
		q.push_back(q.front());
		q.pop_front();

	}

	return q.front();
}





int main() {
	cin >> N;

	for (int i = 1; i <= N; i++)
		q.push_back(i);

	cout << rotate();

}