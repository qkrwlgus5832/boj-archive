#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int N;

string N1[101][500];
string bla = "     ";
void star(int n) {
	
	 if (n == 2) {
		N1[1][0] = "*****";
		N1[1][1] = "*";
		N1[1][2] = "* ***";
		N1[1][3] = "* * *";
		N1[1][4] = "* * *";
		N1[1][5] = "*   *";
		N1[1][6] = "*****";
		return;
	}
	else  {
		star(n - 1);
		N1[n - 1][0] = N1[n - 2][0] + "****";
		N1[n - 1][1] = "*";
	
		for (int i = 0; i < 7+(n - 3) * 4; i++) {
			if (i == 0)
				N1[n - 1][i + 2] = "* " + N1[n - 2][i] + "**";
			else if (i==1)
				N1[n - 1][i + 2] = "* " + N1[n - 2][i] + bla + "*";
			else {
				N1[n - 1][i + 2] = "* " + N1[n - 2][i] + " *";
				
				
			}
		}
		bla = bla + "  ";

		N1[n - 1][7 + (n - 2) * 4 - 2] = "*" + bla + "*";
		N1[n - 1][7+(n-2) * 4 - 1] = N1[n - 1][0];
		bla = bla + "  ";
		}

}



int main() {
	cin >> N;
	
	if (N == 1)
		cout << "*"<< endl;
	else {
		star(N);
		for (int i = 0; i < 7 + (N - 2) * 4; i++) {
			cout << N1[N - 1][i] << endl;
		}
	}
}