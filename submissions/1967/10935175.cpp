#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n;

vector <pair <int, int>> v[10001];
bool check[10001];

int maxl = 0;
int maxi = 0;
void dfs(int i, int length) {

	int f = 0;
	for (int j = 0; j < v[i].size(); j++) {
		if (check[v[i][j].first] == false) {
			f = 1;
			check[v[i][j].first] = true;
			dfs(v[i][j].first, length+ v[i][j].second);
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
	cin >> n;
	int tmp1, tmp2;
	int length;


	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d %d", &tmp1, &tmp2, &length);
		v[tmp1].push_back(make_pair(tmp2, length));
		v[tmp2].push_back(make_pair(tmp1, length));
	}


	check[1] = true;
	dfs(1,0);


	memset(check, false, sizeof(check));

	check[maxi] = true;
	maxl = 0;
	dfs(maxi, 0);

	cout << maxl;


}
