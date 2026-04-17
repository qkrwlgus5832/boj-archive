#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <memory.h>
using namespace std;

int V;

vector <pair <int, int>> v[100001];
bool check[100001];

int maxl = 0;
int maxi = 0;
void dfs(int i, int length) {

	int f = 0;
	for (int j = 0; j < v[i].size(); j++) {
		if (check[v[i][j].first] == false) {
			f = 1;
			check[v[i][j].first] = true;
			dfs(v[i][j].first, length + v[i][j].second);
		}

	}
	if (f == 0) {
		if (maxl < length) {
			maxi = i;
			maxl = length;
		}
	}

}
int main() {
	cin >> V;
	int node;
	int tmp1, tmp2;
	int length;



	for (int i = 1; i <= V; i++)
	{
		scanf("%d", &node);
		while (1) {
			scanf("%d", &tmp1);
			if (tmp1 == -1)
				break;
			scanf("%d", &tmp2);
			v[node].push_back(make_pair(tmp1, tmp2));
			v[tmp1].push_back(make_pair(node, tmp2));
		}

	}


	check[1] = true;
	dfs(1, 0);


	memset(check, false, sizeof(check));

	check[maxi] = true;
	maxl = 0;
	dfs(maxi, 0);

	cout << maxl;


}
