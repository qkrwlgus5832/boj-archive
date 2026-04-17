#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v2;
vector <int> v;

bool N1[9];
int N, M;


void recursion(int i1) {

	if (v.size() == M) {
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}

	for (int i = i1; i < v2.size(); i++) {
		if (N1[i] == false) {
			
			v.push_back(v2[i]);
			N1[i] = true;
			recursion(i + 1);
			v.pop_back();
			N1[i] = false;
		}
		
		
	}

}

int main() {
	cin >> N >> M;
	int tmp;

 	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v2.push_back(tmp);
	}




	sort(v2.begin(), v2.end());
	recursion(0);


}