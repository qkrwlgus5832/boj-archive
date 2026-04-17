#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a, b;

int DP[1001][1001] = { 0, };

int flag = 0;
void recursion(int a, int b) {
	int min1 = -1;
		if (a >= 3 && b >= 1) {
			if (a - 3 == 0 && b - 1 == 0)
				flag = 1;
			if (DP[a-3][b-1] ==0)
			 recursion(a - 3, b - 1);
			if (min1 ==-1)
			min1= DP[a - 3][b - 1] + 1;
			else
				min1 = min(min1, DP[a - 3][b-1] + 1);
		}

		 if (a >= 1) {
			if (DP[a-1][b]==0)
			recursion(a - 1, b);
			if (min1 == -1)
				min1 = DP[a - 1][b] + 1;
			else
			min1 = min(min1, DP[a - 1][b] + 1);
		}

		if (b >= 3 && a >= 1) {
			if (b - 3 == 0 && a - 1 == 0)
				flag = 1;
			if (DP[a - 1][b - 3] == 0)
				recursion(a - 1, b - 3);
			if (min1 == -1)
				min1 = DP[a - 1][b - 3] + 1;
			else
			min1 = min(min1, DP[a - 1][b - 3] + 1);
	

		}

		 if (b >= 1) {
			if (DP[a][b-1] ==0)
			recursion(a, b - 1);
			if (min1 == -1)
				min1 = DP[a][b - 1] + 1;
			else
			min1 = min(min1, DP[a][b - 1] + 1);
		}


		 DP[a][b] = min1;
	
}


int main() {
	cin >> a >> b;


	long long count = 0;
	if (a == 0 && b == 0)
		cout << "Bob";



	else {


		if (a == 1 && b == 0 || a == 0 && b == 1)
			cout << "Alice";
		else if (a == 1 && b == 3 || a == 3 && b == 1)
			cout << "Bob";


		DP[1][3] = 1;
		DP[3][1] = 1;
		DP[1][0] = 1;
		DP[0][1] = 1;

		if (!((a == 1 && b == 0) || (a == 1 && b == 3) || (a == 0 && b == 1) || (a == 3 && b == 1))) {
			recursion(a, b);
			if (flag == 1) {
				cout << "Bob";
			}
			else {
				if ((DP[a][b] - 1) % 2 == 0)
					cout << "Alice";
				else
					cout << "Bob";
			}

		}



	
	
		
	}



}