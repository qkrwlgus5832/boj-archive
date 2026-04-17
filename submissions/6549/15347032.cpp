#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int n;
vector <int> histogram;
vector <pair <int, int>> segmenttree[30];

int result = 0;

pair <int, int> makesegmenttree(int level, int rangestart, int rangeend) {
	if (rangestart == rangeend) {
		segmenttree[level].push_back(make_pair(histogram[rangestart], rangestart));
		return make_pair(histogram[rangestart], rangestart);
	}
	segmenttree[level].push_back(makesegmenttree(level * 2 + 1, rangestart, (rangestart + rangeend)  /2 ));
	segmenttree[level].push_back(makesegmenttree(level * 2 + 2, (rangestart + rangeend) / 2 + 1, rangeend ));

	if (segmenttree[level][0].first <= segmenttree[level][1].first)
		return segmenttree[level][0];
	else
		return segmenttree[level][1];
	
}

pair <int, int> querymin(int level , int rangestart, int rangend, int x, int y) {
	if (x == y) {
		if (rangestart <= x && x <= rangend)
			return segmenttree[level][0];
		else
			return make_pair(INT_MAX, x);
	}
	else if (rangestart <= x && y <= rangend) {
		if (segmenttree[level][0].first <= segmenttree[level][1].first)
			return segmenttree[level][0];
		else
			return segmenttree[level][1];
	}
	else {
		pair <int, int> tmp1 = querymin(level * 2 + 1, rangestart, rangend, x, (x + y) / 2);
		pair <int, int> tmp2 = querymin(level * 2 + 2, rangestart, rangend, (x+y)/2 + 1, y);
		if (tmp1.first <= tmp2.first)
			return tmp1;
		else
			return tmp2;

	}

}

void divdeandconquer(int rangestart, int rangeend, int n) {
	if (rangestart > rangeend) {
		return;
	}
	else if (rangestart ==  rangeend) {
		result = max(result, histogram[rangestart]);
		return;
	}
	pair <int, int> queryresult = querymin(0, rangestart, rangeend, 0, n-1);
	result = max(result, (rangeend - rangestart + 1) * queryresult.first);
	
	divdeandconquer(rangestart, queryresult.second - 1, n);
	divdeandconquer(queryresult.second + 1, rangeend, n);


}

void segmenttreeclear() {
	for (int i = 0; i < 30; i++) {
		segmenttree[i].clear();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int tmp;
	while (1) {
		cin >> n;
		if (n == 0) 
			break;
		histogram.clear();

		for (int i = 0; i < n; i++) {
			cin >> tmp;
			histogram.push_back(tmp);
		}
		segmenttreeclear();
		makesegmenttree(0, 0, n-1);

		result = 0;
		divdeandconquer(0, n - 1, n);
		cout << result << endl;
	}

}