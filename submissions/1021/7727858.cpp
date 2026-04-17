#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int N;
int M;

deque <int> q;

int tmp;
int rotate(int a) {
	int qlry1 = 0;
	int qlry2 = 1;

	for (int i = 0; i < q.size(); i++) {
		if (a == q[i]) {
			break;
		}
		else
			qlry1++;

	}

	for (int i = q.size() - 1; i >= 0; i--) {
		if (a == q[i]) {
			break;
		}
		else {
			qlry2 = qlry2 + 1;
	
		}
	}

	if (qlry1 < qlry2) {
		while (q.front() != a) {
			q.push_back(q.front());
			q.pop_front();
			
		}
		q.pop_front();
	
		return qlry1;
	}
	else {
		while (q.front() != a) {
			q.push_front(q.back());
			q.pop_back();
			
		}
		q.pop_front();
		
		return qlry2;
	}

}





int main() {
	cin >> N >> M;
	int result = 0;

	for (int i = 1; i <= N; i++)
		q.push_back(i);

	
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (tmp == q.front())
			q.pop_front();
		else
		result = result + rotate(tmp);

	}


	cout << result;


}