#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

vector <int> v;
vector <int> v2;
int tmp = 0;

int tmp2[600][12];
int dp[100];


void recursion2(int N) {
	for (int i = 0; i < N - 3; i++) {
		dp[3 + i] = dp[i] + dp[i + 1] + dp[i + 2];
	}

}




void recursion(int N) {

	if (N == 1) {
		tmp2[0][0] = 1;
		return;
	}
	else if (N == 2) {
		recursion(N - 1);
		tmp2[1][0] = 11;
		tmp2[1][1] = 2;
		
	}

	else if (N == 3) {
		recursion(N - 1);
		tmp2[2][0] = 111;
		tmp2[2][1] = 12;
		tmp2[2][2] = 21;
		tmp2[2][3] = 3;
		
	}

	else {
		recursion(N - 1);
		for (int i = 0; i < dp[N - 2]; i++) {
			tmp2[N - 1][i] = tmp2[N - 2][i] * 10 + 1;
			
		}
		for (int i = dp[N - 2]; i < dp[N - 3] + dp[N - 2]; i++) {
			tmp2[N - 1][i] = tmp2[N - 3][i- dp[N-2]] * 10 + 2;
		
		}
		for (int i = dp[N - 2] + dp[N - 3]; i < dp[N - 4] + dp[N - 2] + dp[N - 3]; i++) {
	
			tmp2[N - 1][i] = tmp2[N - 4][i -dp[N-2] - dp[N-3]] *10 + 3;

		
		}
	
	}


}









int n;

int main() {
	int n;
	int k;

	cin >> n >> k;

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;


	recursion2(n);
	recursion(n);

	if (n >= 4) {
		for (int i = 0; i < dp[n - 1]; i++) {
			int a = tmp2[n - 1][i];
			while (a < pow(10, n - 1))
				a = a * 10;
			v.push_back(a);
		}


		sort(v.begin(), v.end());
	}
	else {
		for (int i = 0; i < dp[n - 1]; i++) {
			int a = tmp2[n - 1][i];
			v.push_back(a);
		}




	}
	if (k > dp[n - 1])
		cout << -1;
	else {

		int wa = v[k - 1];
		for (int i= 0; i<n; i++)  {
			if (wa % 10 == 0) {
				wa = wa / 10;
				continue;
			}
			else if (i == n - 1) {
				v2.push_back(wa % 10);
				wa = wa / 10;
			}
			else {
				v2.push_back(wa % 10);
				wa = wa / 10;
			}
			}
		}

	int i2 = v2.size();
	for (int i = i2-1; i >= 0; i--) {
		if (i == 0)
			cout << v2[i];
		else
		cout << v2[i] << "+";
	}

}
	
