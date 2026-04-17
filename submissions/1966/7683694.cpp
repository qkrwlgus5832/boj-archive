#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>



int N;
int M;
using namespace std;


typedef struct p1 {
	int index;
	int priority;
}p1;


queue <p1> q;
priority_queue <int> q2;

vector <int> v;


int tmp[1000];

int printerq() {
	int i3 = 1;
	for (int i = 0; i < N; i++) {
		q.push({ i, tmp[i] });
	}
	for (int i = 0; i < N; i++) {
		q2.push(tmp[i]);
	}


	while (!q.empty()) {
		if (q.front().priority < q2.top()) {
			q.push(q.front());
			q.pop();
		}
		else {
			if (q.front().index == M) {
				break;
			}
			else {
				q.pop();
				q2.pop();
				i3++;
			}

		}

	}
	return i3;
}


int main() {
	int test;
	cin >> test;





	
	for (int i = 0; i < test; i++) {
		cin >> N >> M;

		for (int j = 0; j < N; j++) {
			cin >> tmp[j];
		}
		v.push_back(printerq());
		while (!q.empty())
			q.pop();
		while (!q2.empty())
			q2.pop();


	}


	for (int i = 0; i < test; i++)
		cout << v[i] << endl;
	

}