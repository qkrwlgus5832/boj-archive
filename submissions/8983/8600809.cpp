#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;
string x;



int M;
int N;
int L;
bool check[100001];
int M1[100001];
int N1[100001];
struct animal{
	int x;
	int y;

};

int main() {
	cin >> M >> N >> L;

	for (int i = 0; i < M; i++) {
		cin >> M1[i];
	}
	struct animal i1[100001];

	for (int i = 0; i < N; i++) {
		int a;
		int b;

		cin >> a >> b;
		i1[i].x = a;
		i1[i].y = b;

	}



	int count = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = abs(M1[i] - i1[j].x) + i1[j].y;
			if (tmp <= L && check[j] == false) {
				count = count + 1;
				check[j] = true;

			}

		}
	}
	cout << count;
}