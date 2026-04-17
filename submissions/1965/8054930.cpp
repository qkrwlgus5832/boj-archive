#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int n;
int arr[10001];
int dp[10001];

vector <int> v;

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	

	dp[0] = 1;


	for (int i = 1; i < n; i++) {
		for (int j = i-1; j >= 0; j--) {
			if (arr[i] > arr[j]) {
				dp[i] = dp[j] + 1;
				break;
			}
		}
	}
	


	for (int i = 0; i < n; i++)
		v.push_back(dp[i]);

	sort(v.begin(), v.end());
	cout << v[v.size() - 1];


}