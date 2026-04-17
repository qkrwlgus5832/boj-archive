#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;

vector <string> v;
char tmp[51];



int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		scanf("%s", tmp);
		string s_tmp(tmp);
		v.push_back(s_tmp);
	}
	
	string result;
	int count = 0;


	for (int i = 0; i < M; i++) {
		int alpha[27];
		memset(alpha, 0, sizeof(alpha));
		int maxd = 0;
		char dd = 'Z' + 1;
		for (int j = 0; j < v.size(); j++) {
			alpha[v[j].at(i) - 'A']++;
			if (alpha[v[j].at(i) - 'A'] > maxd) {
				dd = v[j].at(i);
				maxd = alpha[v[j].at(i) - 'A'];
			}
			else if (alpha[v[j].at(i) -'A'] == maxd) {
				dd = min(dd, v[j].at(i));
			}
		}
		result = result + dd;
		count = count + v.size() - maxd;
	}
	cout << result << endl;
	cout << count;

}