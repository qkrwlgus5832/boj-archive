#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>



using namespace std;

vector <int> v;

int result = 0;

int N, C, W;

void DFS(int x, int cuttedcount, int sellcount, int depth, int cost) {
	if (depth == v.size()) {
		result = max(result, cost);
		return;
	}
	else if (cost < 0)
		return;

	DFS(x, cuttedcount, sellcount, depth + 1, cost);

	int treelength = v[depth];
	int count = 0;
	while (1) {
		if (treelength == x) {
			treelength -= x;
			DFS(x, cuttedcount + count, sellcount + count + 1, depth + 1, cost + (W * x) * (count + 1) - C * count);
		}
		else if (treelength > x) {
			treelength -= x;
			count++;
			DFS(x, cuttedcount + count, sellcount + count, depth + 1, cost + (W * x) * count - C * count);
		}
		else
			break;
	}
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