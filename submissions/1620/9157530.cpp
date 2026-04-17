#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <string>
#include<algorithm>

using namespace std;
vector<pair<string, int > > v;
string v1[100001];
int N;
int M;



int binary_search(int x, int y, string x1) {

	if ( v[(x + y) / 2].first == x1 ) {
		return v[(x + y) / 2].second;
	}
	else if (v[(x + y) / 2].first < x1) {
		return binary_search((x + y) / 2 + 1, y, x1);
	
	}

	else if (v[(x + y) / 2].first > x1) {
		return binary_search(x, (x + y) / 2-1 , x1);
	}
}

int main()
{

	
	cin >> N >> M;
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(pair<string, int>(tmp, i + 1));
		v1[i + 1] = tmp;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (tmp.find_first_of("0123456789") <= 6) {
			cout << v1[stoi(tmp)] << endl;
		}
		else {
			cout << binary_search(0, N - 1, tmp) << endl;
		}
	}
}
