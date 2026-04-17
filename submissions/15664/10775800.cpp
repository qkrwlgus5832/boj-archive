#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;


int N, M;
int N2[10001];
char N1[10][10];
int index[10001];
vector <pair <int, int>> vN;

string v;
string indexv;
char tmp = ' ';
string prevv = "";
void recursion(int i1, int i2) {

	if (i1== M) {
		const char *s = v.c_str();
		v.pop_back();
		if (indexv > prevv) {
			prevv= indexv;
			printf("%s\n", s);
		}
	

		int dd = v.rfind(" ");
		if (dd == -1) {
			v.clear();
		}
		else {
			v.erase(dd+1, v.size() - (dd + 1));
		}
		indexv.pop_back();
		return;
	}

	for (int i = i2; i < N; i++) {
		string tmp1 = N1[i];
		v = v + tmp1;
		v.push_back(tmp);
		char dd[6];
		sprintf(dd, "%d", index[N2[i]]);
		string tmpd = dd;
		indexv += tmpd;
		recursion(i1+1, i+1);
	}

	if (v.size() >= 2) {
		v.pop_back();
		int dd = v.rfind(" ");
		if (dd == -1) {
			v.clear();
		}
		else {
			v.erase(dd+1, v.size() - (dd + 1));
		}

		indexv.pop_back();

	}

}

int main() {
	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N; i++){
		scanf("%d", &N2[i]);
		
	}


	sort(N2, N2+N);


	int dd=0;


	for (int i = 0; i < N; i++)
	{
		if (i == 0) {
			index[N2[i]] = ++dd;
		}
		else if (N2[i] != N2[i-1]){
			index[N2[i]] = ++dd;
		}
		else
		index[N2[i]] = dd;

	}
	for (int i = 0; i < N; i++) {
		sprintf(N1[i], "%d", N2[i]);
	}

	recursion(0, 0);


}