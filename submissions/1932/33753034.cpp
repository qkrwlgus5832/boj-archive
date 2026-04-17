#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int triangle[502][502];
int dpArray[502][502];


void dpdp(){
	for (int i = n+1; i >= 1; i--) {
		for (int j = i; j >= 1; j--) {
			dpArray[i - 1][j] = max(dpArray[i-1][j], dpArray[i][j] + triangle[i][j]);
			dpArray[i - 1][j - 1] = max(dpArray[i - 1][j - 1], dpArray[i][j] + triangle[i][j]);
		}
	}
}

int main() {

	cin >> n;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &triangle[i][j]);
		}
	}

	dpdp();

	cout << dpArray[0][0];
	//system("Pause");
}