#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
int N;

int graph[129][129];
int check[129][129];
using namespace std;


int count2 = 0;
int count3 = 0;

void white(int x,int y, int x1, int y1) {
	

	int f = 1;
	
	for (int i = x; i < x1; i++) {
		for (int j = y; j < y1; j++) {
			if (graph[i][j] == 1)
				f = 0;
		}
	}
	
	if (f == 1) {
		count2 = count2 + 1;
		/*for (int i = x; i < x1; i++) {
			for (int j = y; j < y1; j++) {
				check[i][j] = 1;
			}
		}
		*/
		return;
	}

	else if (x1 - x == 1 && y1 - y == 1) {
		return;
	}
	int a = (x1 - x) / 2;

	white(x,y,x1-a,y1-a);

	white(x,y+a,x1-a,y1);
	white(x+a,y,x1,y1-a);
	white(x+a,y+a,x1,y1);
}

void blue(int x, int y, int x1, int y1) {


	int f = 1;
	for (int i = x; i < x1; i++) {
		for (int j = y; j < y1; j++) {
			if (graph[i][j] == 0)
				f = 0;
		}
	}

	if (f == 1) {
		count3 = count3 + 1;
		/*for (int i = x; i < x1; i++) {
		for (int j = y; j < y1; j++) {
		check[i][j] = 1;
		}
		}
		*/
		return;
	}

	else if (x1 - x == 1 && y1 - y == 1) {
		return;
	}
	int a = (x1 - x) / 2;

	blue(x, y, x1 - a, y1 - a);

	blue(x, y + a, x1 - a, y1);
	blue(x + a, y, x1, y1 - a);
	blue(x + a, y + a, x1, y1);
}





int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	white(0, 0, N, N);
	blue(0, 0, N, N);
	cout << count2 << endl;
	cout << count3;


}
