#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int n;
int arr[10001];
int dp[10001];

vector <int> v;
vector <int> v2;
int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	

	dp[0] = 1;





	for (int i = 1; i < n; i++) {
		int f = 0;
		int max = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j]) {
				if (f == 0) {
				 max = dp[j] + 1;
					f = f + 1;
				}

				else {
					if (max < dp[j] + 1)
						max = dp[j] + 1;
				}
			}
		}
		dp[i] = max;
	}


	for (int i = 0; i < n; i++)
		v.push_back(dp[i]);

	sort(v.begin(), v.end());


	cout << v[v.size() - 1];


}