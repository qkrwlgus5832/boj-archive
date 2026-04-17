#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int N, K;
int tmp;
vector <int> v;
deque <int> v2;
map <int, int> ma;

bool check[10001];
int main() {
	cin >> N;
	cin >> K;
	int tmp;



	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		if (ma.find(tmp) == ma.end()) {
			v.push_back(tmp);
			ma.insert(make_pair(tmp, 1));
		}
	}

	sort(v.begin(), v.end());



	for (int i = 1; i < v.size(); i++) {
		v2.push_back(v[i] - v[i - 1]);
	}

	sort(v2.begin(), v2.end());
	long long result = 0;
	int count = 0;

	while (1) {
		if (v.size() - count <= K)
			break;
		result += v2.at(count);

		count++;

	}		



	cout << result;
}