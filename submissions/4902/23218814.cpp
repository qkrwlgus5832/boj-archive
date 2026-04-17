#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector <int> triangle[401];

int getTriangeSum(int i, int j ,int size, int N) {
	int sum = 0;
	for (int h = 0; h < size; h++) {
		for (int w = 0; w < h * 2 + 1; w++) {
			if (i + h >= N || j + w >= triangle[i + h].size()) { // 범위를 넘어가면 그냥 INT_MIN을 리턴
				return INT_MIN;
			}
			sum += triangle[i + h][j + w];
		}
	}
	return sum;
}
int getAnswer( int N) {
	int answer = 0;

	for (int size = 1; size <= N; size++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i * 2 + 1; j+=2) {
				answer = max(answer, getTriangeSum(i, j, size, N));
			}
		}
	}
	return answer;
}
int main() {
	int N;

	int testCase = 1;

	while (1) {

		for (int i = 0; i < 400; i++) {
			triangle[i].clear();
		}

		scanf("%d", &N);

		if (N == 0)
			break;
		
		int input;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 2 * i + 1; j++) {
				scanf("%d", &input);
				triangle[i].push_back(input);
			}
		}
		printf("%d. %d\n", testCase++, getAnswer(N));

	}
	//system("Pause");
}
