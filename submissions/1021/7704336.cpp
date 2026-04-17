#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N;
int M;
vector <int> v;
deque <int> q;



int min() {
	int count = 0;
	int i = 0;
	while (1) {
		if (i == v.size())
			break;
		else if (v[i] == q.front()) {
			q.pop_front();
			i++;

		}
		else if (v[i] > q.front()) {
			int a = q.front();
			q.pop_front();
			q.push_back(a);
			count++;
		}
		else if (v[i] < q.front()) {
			int a = q.back();
			q.pop_back();
			q.push_front(a);
			count++;
		}
	}
	return count;
}








int main() {
	cin >> N;
	cin >> M;
	int tmp;
	for (int i = 1; i <= N; i++) {
		q.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	cout << min();

}