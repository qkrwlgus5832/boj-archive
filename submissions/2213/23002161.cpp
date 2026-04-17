#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

vector <int> graph[10001];
int dp[10001][2];
int check[10001];
vector <int> course[10001][2];


void dfs(int x) {

	int sum1 = 0;
	int sum2 = 0;

	vector <int> tmp1;
	vector <int> tmp2;

	for (int i = 0; i < graph[x].size(); i++) {
		if (check[graph[x][i]] == false) {
			check[graph[x][i]] = true;
			dfs(graph[x][i]);
			sum1 += dp[graph[x][i]][0];
			tmp1.insert(tmp1.end(), course[graph[x][i]][0].begin(), course[graph[x][i]][0].end());

			if (dp[graph[x][i]][0] < dp[graph[x][i]][1]) {
				sum2 += dp[graph[x][i]][1];
				tmp2.insert(tmp2.end(), course[graph[x][i]][1].begin(), course[graph[x][i]][1].end());
			}
			else{
				sum2 += dp[graph[x][i]][0];
				tmp2.insert(tmp2.end(), course[graph[x][i]][0].begin(), course[graph[x][i]][0].end());
			}
			
		}

	}

	dp[x][0] = sum2;
	course[x][0] = tmp2;

	dp[x][1] = dp[x][1] + sum1;
	tmp1.push_back(x);
	course[x][1] = tmp1;

}

int main() {
	int N;

	cin >> N;

	int people;

	for (int i = 0; i < N; i++) {
		scanf("%d", &dp[i + 1][1]);
	}

	int node1, node2;

	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &node1, &node2);
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}


	check[1] = true;


	dfs(1);

	if (dp[1][0] < dp[1][1]) {
		cout << dp[1][1] << endl;

		sort(course[1][1].begin(), course[1][1].end());

		for (int i = 0; i < course[1][1].size(); i++) {
			printf("%d ", course[1][1][i]);
		}
	}
	else {
		cout << dp[1][0] << endl;
		sort(course[1][0].begin(), course[1][0].end());

		for (int i = 0; i < course[1][0].size(); i++) {
			printf("%d ", course[1][0][i]);
		}

	}

	//system("Pause");
}
