#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector <int> A;
vector <int> B;
vector <int> C;
vector <int> D;

int N1[4];
int n;

int result = 0;

map <int, int> frontmap;
//map <int, int> backmap;
vector <int> backmap;

void frontrecursion(int count) {
	if (count == 2) {
		int tmp = A[N1[0]] + B[N1[1]];


		frontmap.insert(make_pair(tmp, 1));

		return;
	}

	for (int i = 0; i < n; i++) {
		N1[count] = i;
		frontrecursion(count + 1);
		//N1[count] = 0;
	}

}


void backrecursion(int count) {
	if (count == 2) {
		int tmp = C[N1[0]] + D[N1[1]];

		backmap.push_back(tmp);
		
		return;
	}

	for (int i = 0; i < n; i++) {
		N1[count] = i;
		backrecursion(count + 1);
		//N1[count] = 0;
	}

}


int main() {
	cin.tie(NULL);
	cin >> n;

	int a, b, c, d;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	frontrecursion(0);
	backrecursion(0);

	
	sort(backmap.begin(), backmap.end());
	int result = 0;
	for (auto mm = frontmap.begin(); mm != frontmap.end(); mm++) {
		//auto dd = backmap.find((mm->first )* -1);
		
		if (binary_search(backmap.begin(), backmap.end(), (mm->first) * -1)) {
			result += (upper_bound(backmap.begin(), backmap.end(), (mm->first) * -1) - lower_bound(backmap.begin(), backmap.end(), (mm->first) * -1));
			//result += (mm->second) * backmap.count((mm->first)* -1);
		}
	}

	cout << result;
	//system("Pause");
}