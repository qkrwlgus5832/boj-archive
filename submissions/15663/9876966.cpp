#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;


vector <int> v;
string prevt = "";
string tmp = "";
vector <int> v2;
vector <int> v3;
bool N1[9];
int N, M;
int i1 = -1;

void recursion(int j) {

	if (tmp.size() == M) {
		if (prevt >= tmp) {
			return;
		}
		for (int i = 0; i < tmp.size(); i++) {
			printf("%d ", v3[v2[tmp.at(i)-48]]);
		}
		printf("\n");
		prevt = tmp;
		return;
	}

	for (int i = 0; i <v2.size() ; i++) {
		if (N1[i] == false) {
			char buf[126];
			sprintf(buf, "%d", v2[i]);
			tmp = tmp + buf;
			N1[i] = true;
			recursion(i);
			N1[i] = false;
			tmp.pop_back();
		}


	}
		
		
}


int main() {
	cin >> N >> M;
	int tmp;

 	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v3.push_back(tmp);
	}

	sort(v3.begin(), v3.end());


	int i1 = 0;



	for (int i = 0; i < v3.size(); i++) {
	
		if (!(i == 0 || v3[i] == v3[i - 1]))
			i1++;

		v2.push_back(i1);

	}
	


	recursion(0);


}