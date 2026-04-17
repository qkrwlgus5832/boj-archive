#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<vector>
#include <string>
#include<algorithm>

using namespace std;

long long N = 1;
long long S;
long long tmp = 0;

int main()
{
	cin >> S;

	while (1) {
		if (tmp + N <= S) {
			tmp = tmp + N;
			N = N + 1;
		}
		else {
			break;
		}


	}
	cout << N-1;
}
