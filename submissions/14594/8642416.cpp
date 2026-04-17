#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


bool check[101][101];


int N;
int M;




int main() {
	cin >> N;
	cin >> M;
	int a;
	int b;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		for (int j = a; j <= b-1; j++) {
			if (check[j][j+1] == 0){
				N = N - 1;
				check[j][j + 1] = 1;
			}
		}
	}
	cout << N;



}