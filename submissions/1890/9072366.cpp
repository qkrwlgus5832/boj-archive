#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int N;
char arr[101][101];
long long DP[101][101];


void dp() {
	for (int i = N - 1; i >= 0;  i--) {
		for (int j = N - 1; j >= 0; j--) {
			int value = arr[i][j];
			if (i + value<= N - 1 && value != 0) {
				DP[i][j] = DP[i][j] + DP[i + value][j];
			}
			if (j + value <= N - 1 && value != 0) {
				DP[i][j] = DP[i][j] + DP[i][j+value];

			}
		}
	}


}
int main(void) {

	cin >> N;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			arr[i][j] = arr[i][j] - 48;
		}
	}


	DP[N - 1][N - 1] = 1;


	dp();
	cout << DP[0][0];

}
