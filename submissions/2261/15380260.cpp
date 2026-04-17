#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

vector <pair <int, int>> v;

vector <pair <int, int>> x;
vector <pair <int, int>> y;


int main() {
	int n;
	cin >> n;
	int tmp1, tmp2;
	for (int i = 0; i < n; i++) {
		cin >> tmp1 >> tmp2;
		v.push_back(make_pair(tmp1, tmp2));
		x.push_back(make_pair(tmp1, i));
		y.push_back(make_pair(tmp2, i));
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int result = INT_MAX;

	for (int i = 1; i < n; i++) {
		int x1 = pow((x[i].first - x[i - 1].first), 2);
		int y1 = pow(v[x[i].second].second - v[x[i - 1].second].second , 2);
		result = min(result, x1 + y1);
	}

	for (int i = 1; i < n; i++) {
		int y1 = pow((y[i].first - y[i - 1].first), 2);
		int x1 = pow(v[y[i].second].first - v[y[i - 1].second].first, 2);
		result = min(result, x1 + y1);
	}
	cout << result;
	//system("Pause");
}