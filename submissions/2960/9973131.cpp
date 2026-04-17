#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int N, K;


int check[1001];
int main() {
	cin >> N >> K;

	
	int count = 0;
	for (int i = 2; i <= N; i++) {
		if (check[i] == true) {
			continue;
		}
		int j = 1;
		while (1) {

		 if (i*j > N)
				break;
			check[i*j] = true;
			j++;
			count++;
			if (count == K) {
				printf("%d", i*j);
				break;
			}
		}


	}
}