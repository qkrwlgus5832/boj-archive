#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
int T;

vector <pair<string, int>> v;

int DP[31][31];

int dress(int n) {
	int result = 0;
	for (int i = 1; i <= v.size(); i++) {
		DP[i][i] = v[i - 1].second;
		result = result + DP[i][i];
	}


	for (int i = 1; i <= v.size() - 1; i++) {
		for (int j = i + 1; j <= v.size(); j++) {
			 DP[i][j] = DP[i][j - 1] * DP[j][j];
			 result = result + DP[i][j];
		}
	}
	return result;

}


int main()
{

	cin >> T;


for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		char cloth[42];
		cin.getline(cloth, 42);
		
		if (n == 0) {
			cout << 0 << endl;
			continue;
		}

		for (int i1 = 0; i1 < n; i1++) {
		

		
			cin.getline(cloth, 42);


			char *ptr = strtok(cloth, " ");

			ptr = strtok(NULL, " ");
			string tmp(ptr);


			int flag = 0;
			for (int j = 0; j < v.size(); j++) {
				if (v[j].first == tmp) {
					v[j].second++;
					flag = 1;

				}
			}
			if (flag == 0) {
				v.push_back(make_pair(tmp, 1));

			}
		}
		cout << dress(n) << endl;
		v.clear();
	
	}

	return 0;
}


