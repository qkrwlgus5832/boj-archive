#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>

using namespace std;

int N, L;

int N1[101][101];

bool check[101][101];
int main() {
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &N1[i][j]);
		}
	}

	int result = 0;

	for (int i = 0; i < N; i++) {
		int currentheight = N1[i][0];
		bool flag = false;
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (currentheight == N1[i][j]) {
				if (count != 0) {
					flag = true;
					count = 0;
					break;
				}
				
				continue;
			}
			else if (currentheight == N1[i][j] + 1){
				count++;
				check[i][j] = true;

				if (count == L) {
					currentheight = N1[i][j];
					count = 0;
				}
			}
			else if (currentheight == N1[i][j] - 1) {
				if (count != 0) {
					flag = true;
					count = 0;
					break;
				}
				int count2 = 0;
				for (int j1 = j-1; j1 >= 0; j1--) {
					if (currentheight != N1[i][j1] || check[i][j1] == true) {
						flag = true;
						break;
					}
					else {
						count2++;
					}
					if (count2 == L) {
						currentheight = N1[i][j];
						break;
					}
				}
				if (count2 < L) {
					flag = true;
					break;
				}
			}
			else {
				flag = true;
				break;
			}
		}
		if (flag == false && count ==0) {
			//cout << i << endl;
			result++;
		}
		/*else
			memset(check[i], false, sizeof(check[i]));*/
	}

	for (int i = 0; i < 101; i++) {
		memset(check[i], 0, sizeof(check[i]));
	}

	for (int i = 0; i < N; i++) {
		int currentheight = N1[0][i];
		bool flag = false;
		int count = 0;
		for (int j = 0; j < N; j++) {
			if (currentheight == N1[j][i]) {
				if (count != 0) {
					flag = true;
					break;
				}

				continue;
			}
			else if (currentheight == N1[j][i] + 1) {
				count++;
				check[j][i] = true;

				if (count == L) {
					currentheight = N1[j][i];
					count = 0;
				}
			}
			else if (currentheight == N1[j][i] - 1) {
				if (count != 0) {
					flag = true;
					break;
				}

				int count2 = 0;
				for (int j1 = j-1; j1 >= 0; j1--) {
					if (currentheight != N1[j1][i] || check[j1][i] == true) {
						flag = true;
						break;
						
					}
					else {
						count2++;
					}
					if (count2 == L) {
						currentheight = N1[j][i];
						break;
					}
				}
				if (count2 < L) {
					flag = true;
					break;
				}
			}
			else {
				flag = true;
				break;
			}
		}
		if (flag == false && count == 0) {
			result++;
		}
	}

	cout << result;
	//system("Pause");
}