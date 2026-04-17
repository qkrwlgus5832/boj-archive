#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N;
int M;
int M1[1000001];
vector <int> v;

int binary_search(int a, int b, int x ) {
	if (a == b) {
		if (v[a] != x) {
			return 0;

		}
		else {
			return 1;
		}
	}
	else if (v[(a + b) / 2] == x) {
		return 1;
	}
	else if (x< v[(a + b) / 2]){
		binary_search(a, ((a + b) / 2)  , x);
	}

	else if (x > v[(a + b) / 2]) {
		binary_search( ((a + b) / 2)+1  , b,  x);
	}



}

int main() {

	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);

	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> M1[i];
	}

	sort(v.begin(), v.end());




	for (int i = 0; i < M; i++) {
		cout << binary_search(0, N-1, M1[i]) << endl;
	}


	system("pause");

}