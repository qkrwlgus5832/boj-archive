#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector <string> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		string phonenumber;
		v.clear();
		for (int i1 = 0; i1 < n; i1++) {
			cin >> phonenumber;
			v.push_back(phonenumber);
		}
		sort(v.begin(), v.end());

		bool result = false;

		for (int i1 = 0; i1 < n- 1; i1++) {
			int minsize = min(v[i1].size(), v[i1 + 1].size());
			bool flag = false;
			for (int j1 = 0; j1 < minsize; j1++) {
				if (v[i1][j1] != v[i1 + 1][j1]) {
					flag = true;
					break;
				}
			}
			if (flag == false) {
				result = true;
				break;
			}

		}
		if (result == true) {
			cout << "NO" << endl;
		}
		else  {
			cout << "YES" << endl;
		}
	}
	//system("Pause");
}