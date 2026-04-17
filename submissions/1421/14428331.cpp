#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>



using namespace std;

vector <int> v;

int result = 0;

int N, C, W;


int gettotal(int x, int sellcount, int cuttedcount) {
	return (sellcount * x * W) - (cuttedcount * C);
}


void DFS(int x, int cuttedcount, int sellcount, int depth, int cost) {
	if (depth == v.size()) {
		result = max(result, (sellcount * x * W) - (cuttedcount * C));
		return;
	}
	else if ((sellcount * x * W )- (cuttedcount * C )< 0)
		return;

	int treelength = v[depth];
	int count = 0;

	int tmpsellcount = 0;
	int tmpcuttedcount = 0;

	if (treelength % x == 0) {
		tmpsellcount = treelength / x;
		tmpcuttedcount = treelength / x - 1;
	}
	else {
		tmpsellcount = treelength / x;
		tmpcuttedcount = treelength / x;

	}
	if (gettotal(x, tmpsellcount, tmpcuttedcount) < 0)
		DFS(x, cuttedcount, sellcount, depth + 1, cost);
	else
		DFS(x, cuttedcount + tmpcuttedcount, sellcount + tmpsellcount, depth + 1, cost);
}

int main() {
	
	cin >> N >> C >> W;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= v[v.size() - 1]; i++) {
		DFS(i, 0, 0, 0, 0);
	}

	cout << result;
	//system("Pause");
}