#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;
int graph[65][65];
int N;
int r;
int c;

int count1 = 0;
int f = 0;
void white(int x, int y, int x1, int y1) {

	if (x1 - x == 2 && y1 - y == 2) {

		for (int i = x; i < x1; i++) {
			for (int j = y; j < y1; j++) {
				if (i == r && j == c) {
					cout << count1;
					return;
				}
				else
					count1 = count1 + 1;
			}

		}


	

	}

	else {
		int a = (x1 - x) / 2;

		white(x, y, x1 - a, y1 - a);
		if (f == 1)
			return;
		white(x, y + a, x1 - a, y1);
		if (f == 1)
			return;
		white(x + a, y, x1, y1 - a);
		if (f == 1)
			return;
		white(x + a, y + a, x1, y1);
		if (f == 1)
			return;


	}





}


int main() {
	cin >> N >> r >> c;



	int b = pow(2, N);



	white(0, 0, b, b);
}