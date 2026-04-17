#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N;
int a[100];
int flag[100];


void suggi() {
	for (int i = 1; i < N; i++) {
	
			int count = 0;
			int i2 = 0;
			for (int i3 = 0; i3 < N; i3++) {
				if (flag[i3] == 0)
					count = count + 1;
				
				if (count == a[i] + 1) {
					i2 = i3;
					break;
				}
				
			}
			flag[i2] = i + 1;


		}
	}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	flag[a[0]] = 1;

	suggi();

	for (int i = 0; i < N; i++)
		cout << flag[i] << " ";

}