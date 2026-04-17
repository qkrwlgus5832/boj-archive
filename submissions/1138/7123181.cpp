#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N;
int a[100];
int flag[100];


void suggi() {
	for (int i = 0; i < N; i++) {
		if (flag[a[i]] == 0) {
			flag[a[i]] = i + 1;
		}
		else {
			int count = 0;
			int i2 = 0;
			for (int i = 0; i < N; i++) {
				if (count == a[i] + 1) {
					i2 = i;
					break;
				}
				if (flag[i] == 0)
					count = count + 1;
			}
			flag[i2] = i + 1;


		}
	}

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	suggi();

	for (int i = 0; i < N; i++)
		cout << flag[i] << " ";

}