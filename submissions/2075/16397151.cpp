#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <functional>
#include <limits.h>
using namespace std;

//priority_queue <int, vector<int>, greater<int>> q;
vector <int> arrayinput[1501];
//int startindex[1501];

int main() {
	int N;
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);
			arrayinput[j].push_back(tmp);
		}
	}
	int count = 0;

	while (1) {
		int beforevalue = 0;
		int maxindex = -1;
		for (int i = 0; i < N; i++) {
			if (arrayinput[i].size() >= 1 && arrayinput[i].back() > beforevalue) {
				beforevalue = arrayinput[i].back();
				maxindex = i;
			}
		}
	
		if (maxindex != -1) {
			count++;
			if (count == N) {
				cout << arrayinput[maxindex].back();
				break;
			}
			else {
				arrayinput[maxindex].pop_back();
				
			}
		}
	}
	//system("Pause");
}