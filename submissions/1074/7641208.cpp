#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int graph[65][65];
int N;
int r;
int c;

int count1 = 0;
void white(int x, int y, int x1, int y1) {


	 if (x1-x  == 1 && y1-y ==1) {
	
		 if (x == r && y== c) {
			 cout << count1;
			 return;
		 }

		 else {
			 count1 = count1 + 1;
			 return;
		 }
				
		}
	
	 else {
		 int a = (x1 - x) / 2;

		 white(x, y, x1 - a, y1 - a);

		 white(x, y + a, x1 - a, y1);
		 white(x + a, y, x1, y1 - a);
		 white(x + a, y + a, x1, y1);
		


	 }

	
	


}


int main() {
	cin >> N>> r >> c;
	


	int b = pow(2, N);



	white(0, 0, b ,b);
}