#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <int, int> m;
vector <int> results;

int N, M;


int main() {
	cin >> N;
	int input;
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if (m.count(input) == 0) {
			m[input] = 1;
		}
		else {
			m[input]++;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d", &input);
		results.push_back(m[input]);
	}

	for (int result : results) {
		printf("%d ", result);
	}
	
	//system("Pause");
}
