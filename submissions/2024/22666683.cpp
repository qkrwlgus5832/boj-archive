#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int>> v;

int main() {
	int M;
	cin >> M;

	int L, R;

	while (1) {
		scanf("%d %d", &L, &R);
		if (L == 0 && R == 0)
			break;
		v.push_back({ L,R });
	}
	
	sort(v.begin(), v.end(), [](const pair <int, int>& a, const pair <int, int>& b) {
		return a.first < b.first;
	});

	int standard = 0;
	int maxRight = INT_MIN;
	int result = 1;

	for (pair <int, int> location : v) {
		if (location.first <= standard) {
			maxRight = max(location.second, maxRight);
		}
		else if (maxRight >= M)
			break;
		else {
			standard = maxRight;
			if (location.first > standard) {
				result = 0;
				break;
			}
			else {
				result++;
				maxRight = max(location.second, maxRight);
			}
		}

	}
	if (maxRight >= M)
		cout << result;
	else
		cout << 0;

	//system("Pause");
}
