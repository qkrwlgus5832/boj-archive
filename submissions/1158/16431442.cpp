#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector <int> v;
vector <int> result;

int main() {
	int N, K;
	cin >> N >> K;
	for (int index = 1; index <= N; index++) {
		v.push_back(index);
	}
	int beforeindex = (K - 1) % v.size(); //index가 0부터 시작하므로
	result.push_back(v[beforeindex]);
	v.erase(v.begin() + beforeindex);

	while (v.size()) {
		beforeindex = (beforeindex + K -1) % v.size(); // 
		result.push_back(v[beforeindex]);
		v.erase(v.begin() + beforeindex);
	}
	printf("<");
	for (int i = 0; i < result.size(); i++) {
		if (i == result.size() - 1) {
			printf("%d", result[i]);
			continue;
		}
		printf("%d, ", result[i]);
	}
	printf(">");
	//system("Pause");
}