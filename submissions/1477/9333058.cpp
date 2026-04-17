#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int N;
int M;
int L;

int check[1000];
vector <int> v2;


int restarea(int x) {
	int count = 0;
	for (int i = 0; i < v2.size(); i++) {
		if (v2[i] >= x && v2[i] % x == 0) {
			count = count + v2[i] / x - 1;
		}
		else if (v2[i] >= x && v2[i] % x >= 1) {
			count = count + v2[i] / x;
		}

	}
	return count;
}



int binary_search(int x, int y, int x1) {
	if (x == y)
		return x;

	else if (restarea((x+y)/2)> x1) {
		return binary_search((x + y) / 2 + 1, y, x1);

	}

	else if (restarea((x+y)/2) <= x1) {
		return binary_search(x, (x + y) / 2, x1);
	}
}



int main() {
	cin >> N >> M >> L;
	vector <int> v;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	v.push_back(L);
	sort(v.begin(), v.end());

	

	v2.push_back(v[0]);
	for (int i = 0; i < N; i++) {
		v2.push_back(v[i + 1] - v[i]); 
	}

	sort(v2.begin(), v2.end());




	int result = binary_search(1, v2[v2.size() - 1], M);


	if (result == 1)
		cout << 1;
	else {
		if (restarea(result) != M) {
			cout << result;
		}
		else {
			for (int i = result; i >= 2; i--) {
				if (restarea(i) == M) {
					continue;
				}
				else {
					cout << i + 1;
					break;
				}
			}
		}

	}

	
}