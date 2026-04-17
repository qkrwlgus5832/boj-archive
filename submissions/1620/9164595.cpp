#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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

	if (v[(x + y) / 2].first == x1) {
		return v[(x + y) / 2].second;
	}
	else if (v[(x + y) / 2].first < x1) {
		return binary_search((x + y) / 2 + 1, y, x1);

	}

	else if (v[(x + y) / 2].first > x1) {
		return binary_search(x, (x + y) / 2 - 1, x1);
	}
}

int main()
{


	cin >> N >> M;
	string tmp;
	char tmp2[21];
	for (int i = 0; i < N; i++) {
		scanf("%s", tmp2);
		tmp = tmp2;
		v.push_back(pair<string, int>(tmp, i + 1));
		v1[i + 1] = tmp;
	}

	sort(v.begin(), v.end());



	for (int i = 0; i < M; i++) {
		scanf("%s", tmp2);
		tmp = tmp2;
		if (tmp.find_first_of("0123456789") <= 6) {
			printf("%s\n", v1[stoi(tmp)].c_str());
		}
		else {
			printf("%d\n", binary_search(0, N - 1, tmp) );
		}
	}
}
