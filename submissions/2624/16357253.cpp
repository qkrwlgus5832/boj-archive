#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair <int, int>> v;

int DP[101][10001];

int main() {
	int T;
	int k;
	cin >> T;
	cin >> k;
	v.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	v.insert(v.begin(), make_pair(-1, -1));
	DP[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		DP[i][0] = 1;
		for (int j = 0; j <= T; j++) {
			for (int i1 = 1; i1 <= v[i].second; i1++) {
				DP[i + 1][j] = DP[i][j];
				if (j + i1 * v[i].first > T)
					break;
				DP[i][j + i1 * v[i].first] += DP[i - 1][j];
			}
		}
	}
	
	cout << DP[k][T];
	//system("Pause");
}