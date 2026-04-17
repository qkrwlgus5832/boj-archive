#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int N;
int K;

int graph[101][101];
char shift[10001];
deque <int> q;
queue <int> q2;
char tmp = 'R';
int goR(int x);
int goL(int x);
int goU(int x);
int goD(int x);
int time = 0;
int BFS() {
	

	
	q.push_front(0);
	
	graph[0][0] = -1;

	while (1) {
		int a = q.front();

		int x1 = a / N;
		int y1 = a% N;
		
		int f1 = 0;
	
			if (tmp == 'R') {
				 f1= goR(a);
				 time = time + 1;
			}
			else if (tmp == 'D') {
				 f1= goD(a);
				 time = time + 1;
			}
			else if (tmp == 'L') {
				 f1= goL(a);
				 time = time + 1;
			}
			else if (tmp == 'U') {
				 f1=goU(a);
				 time = time + 1;
			}


			if (f1 == -1)
				return time;

			else {
				if (!q2.empty() && time== q2.front()) {
					if (tmp == 'R') {
						if (shift[q2.front()] == 'L') {
							tmp = 'U';

						}
						else if (shift[q2.front()] == 'D') {
							tmp = 'D';

						}
					}
					else if (tmp == 'U') {
						if (shift[q2.front()] == 'L') {
							tmp = 'L';

						}
						else if (shift[q2.front()] == 'D') {
							tmp = 'R';

						}
					}

						else if (tmp == 'D') {
							if (shift[q2.front()] == 'L') {
								tmp = 'R';

							}
							else if (shift[q2.front()] == 'D') {
								tmp = 'L';

							}
						}


						else if (tmp == 'L') {
							if (shift[q2.front()] == 'L') {
								tmp = 'D';

							}
							else if (shift[q2.front()] == 'D') {
								tmp = 'U';

							}
						}
					
					q2.pop();
				}
			}



	}

}
int goR(int x) {
	int x1 = x / N;
	int y1 = x% N;

	if (y1 + 1 > N-1 || graph[x1][y1 + 1] == -1 ) {
		return -1;
	}
	else {
		if (graph[x1][y1 + 1] == 1) {
			graph[x1][y1 + 1] = -1;
			q.push_front(x1*N + y1 + 1);
		}
		else {
			q.push_front(x1*N + y1 + 1);
			graph[x1][y1 + 1] = -1;
			int d = q.back();
			int x2 = d / N;
			int y2 = d%N;
			q.pop_back();
			graph[x2][y2] = 0;
			
		}

		return 0;
	}
}


int goD(int x) {
	int x1 = x / N;
	int y1 = x% N;

	if (x1 + 1 > N - 1 || graph[x1 + 1][y1] == -1) {
		return -1;
	}

	else {

		if (graph[x1 + 1][y1] == 1) {
			graph[x1 + 1][y1] = -1;
			q.push_front((x1 + 1)*N + y1);
		}

		else {
			q.push_front((x1 + 1)*N + y1);
			graph[x1 + 1][y1] = -1;
			int d = q.back();
			int x2 = d / N;
			int y2 = d%N;
			q.pop_back();
			graph[x2][y2] = 0;

		}
		return 0;
	}
}
int goL(int x) {
	int x1 = x / N;
	int y1 = x% N;

	if (y1 - 1 < 0 || graph[x1][y1 -1 ] == -1) {
		return -1;
	}
	else {
		if (graph[x1][y1 - 1] == 1) {
			graph[x1][y1 - 1] = -1;
			q.push_front((x1)*N + (y1 - 1));
		}

		else {
			q.push_front(x1*N + y1 - 1);
			graph[x1][y1 - 1] = -1;
			int d = q.back();
			int x2 = d / N;
			int y2 = d%N;
			q.pop_back();
			graph[x2][y2] = 0;

		}
		return 0;
	}

}
int goU(int x) {
	int x1 = x / N;
	int y1 = x% N;

	if (x1 -1 < 0 || graph[x1 - 1][y1] == -1) {
		return -1;
	}

	else {
		if (graph[x1 - 1][y1] == 1) {
			graph[x1 - 1][y1] = -1;
			q.push_front((x1 - 1)*N + (y1));
		}
		else {
			q.push_front((x1 - 1)*N + y1);
			graph[x1 - 1][y1] = -1;
			int d = q.back();
			int x2 = d / N;
			int y2 = d%N;
			q.pop_back();
			graph[x2][y2] = 0;
		}
		return 0;
	}


}






int main() {
	cin >> N;
	cin >> K;

	int a;
	int b;

	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		graph[a-1][b-1] = 1;
	}
	int L;

	cin >> L;
	int X;
	char C;

	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		q2.push(X);
		shift[X] = C;
	}
	




	
	cout << BFS();

	
	

}