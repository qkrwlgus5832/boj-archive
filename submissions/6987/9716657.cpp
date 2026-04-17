#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int arr[18];
int country[6][3];
vector <pair<int, int>> v;

int flag = 0; 
int result[4];

int recursion(int i, int game) {
	int f1 = 0;
	if (i >= 0) {
		if (game == 1) {
			country[v[i].first][0]++;
			country[v[i].second][2]++;
		}
		else if (game == 0) {
			country[v[i].first][1]++;
			country[v[i].second][1]++;
		}
		else if (game == -1) {
			country[v[i].first][2]++;
			country[v[i].second][0]++;
		}
	}

	if (i == 14) {
		int f = 0;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (country[i][j] !=arr[i * 3 + j])
					f = 1;
			}
		}
		if (f == 0) {
			/*for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 3; j++) {
					cout << country[i][j] << " ";
				}
			}*/
			return 1;
		}
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			if (country[i][j] > arr[i * 3 + j])
				f1 = 1;
		}
	}
	if (f1 == 0) {
		if (recursion(i + 1, 1)==1)
			return 1;
		 if (recursion(i + 1, 0)==1)
			return 1;
		 if (recursion(i + 1, -1)==1)
			return 1;
	}
	if (i >= 0) {
		if (game == 1) {
			country[v[i].first][0]--;
			country[v[i].second][2]--;
		}
		else if (game == 0) {
			country[v[i].first][1]--;
			country[v[i].second][1]--;
		}
		else if (game == -1) {
			country[v[i].first][2]--;
			country[v[i].second][0]--;
		}
	}

	return 0;
}



int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 6; j++) {
			v.push_back(make_pair(i, j));
		}
	}




	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 18; j++) {
			cin >> arr[j];
			
		}

		result[i]= recursion(-1, 0);
		memset(country, 0, sizeof(country));
	}


	for (int i = 0; i < 4; i++) {
		if (i == 3)
			cout << result[i];
		else
		cout << result[i] << " ";
	}

		





}