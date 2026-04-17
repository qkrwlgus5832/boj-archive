#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

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
	for (int i = i1; i <= N; i++) {

			v.push_back(i);
		
			recursion(i);
			v.pop_back();

		
		
	}

}

int main() {
	cin >> N >> M;



	recursion(1);


}