#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;
string x;



int M;
int N;
int L;
vector <int> M1;
int N1[100001];
struct animal {
	int x;
	int y;

};

int binary_search(int a, int b, int x) {
	if (a == b) {
		return a;
	}
	else if (x <= M1[(a + b) / 2]) {
		binary_search(a, (a + b) / 2, x);
	}
	else if(x>M1[(a+b)/2]){
		binary_search((a+b)/2+1, b, x);
	}

}
int main() {
	cin >> M >> N >> L;

	int tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		M1.push_back(tmp);
	}

	sort(M1.begin(), M1.end());


	struct animal i1[100001];

	for (int i = 0; i < N; i++) {
		int a;
		int b;

		cin >> a >> b;
		i1[i].x = a;
		i1[i].y = b;

	}



	int count = 0;
	int result = 0;
	for (int i = 0; i < N; i++) {
		result = binary_search(0, M-1, i1[i].x);
		if (abs(M1[result] - i1[i].x) + i1[i].y <= L)
			count++;
		else if (result >= 1 && abs(M1[result - 1] - i1[i].x) + i1[i].y <= L)
			count++;
		else if (result <= M - 2 && abs(M1[result+1] - i1[i].x) + i1[i].y <= L)
			count++;
	}

	cout << count;
}