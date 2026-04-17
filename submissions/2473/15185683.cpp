#define _CRT_SECURRE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
 
vector <int> v;
vector <int> answer;

int main() {
	int N;
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	
	int answer1, answer2, answer3;
	int min1 = INT_MAX;

	for (int i = 0; i < N; i++) {
		int left = 0;
		int right = N - 1;
		
		int S = v[i] * -1;
	
		while (1) {
			if (left == i) {
				left++;
				continue;
			}
			else if (right == i) {
				right--;
				continue;
			}

			if (left >= right)
				break;

			if (abs(v[left] + v[right] - S) < min1) {
				answer1 = v[left];
				answer2 = v[right];
				answer3 = v[i];
				min1 = abs(v[left] + v[right] - S);
			}
			if (v[left] + v[right] > S) {
				right--;
			}
			else if (v[left] + v[right] <= S) {
				left++;
			}
		}
	}
	answer.push_back(answer1);
	answer.push_back(answer2);

	answer.push_back(answer3);

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	//system("Pause");

}