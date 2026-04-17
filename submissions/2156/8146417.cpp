#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

int arr[10002];
int dp[10002];
vector <int> v;
void dpdp() {

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i-1]);
		dp[i] = max(dp[i] , dp[i - 3] + arr[i-1] + arr[i - 2]);
	}

	

}
int main() {

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dpdp();

	dp[1] = arr[1];
	dp[2] = arr[2] + arr[1];



	for (int i = 1; i <= n; i++)
		v.push_back(dp[i]);

	sort(v.begin(), v.end());
	cout << v[n-1];
}