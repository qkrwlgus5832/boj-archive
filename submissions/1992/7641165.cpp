#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int graph[65][65];
int N;

void white(int x, int y, int x1, int y1) {


	int f = 1;
	int f1 = 1;
	for (int i = x; i < x1; i++) {
		for (int j = y; j < y1; j++) {
			if (graph[i][j] == 1)
				f = 0;
		}
	}

	for (int i = x; i < x1; i++) {
		for (int j = y; j < y1; j++) {
			if (graph[i][j] == 0)
				f1 = 0;
		}
	}

	 if (f == 1) {
		cout << 0;
		return;
	}

	else if (f1 == 1) {
		cout << 1;
		return;
	}
	else if (x1 - x == 1 && y1 - y == 1) {
		return;
	}
	else {
		cout << "(" ;
		int a = (x1 - x) / 2;

		white(x, y, x1 - a, y1 - a);

		white(x, y + a, x1 - a, y1);
		white(x + a, y, x1, y1 - a);
		white(x + a, y + a, x1, y1);
		cout << ")" ;
	}

		
	
	


}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &graph[i][j]);
		}

	}




	white(0, 0, N, N);
}