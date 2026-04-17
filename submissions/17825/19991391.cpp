#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dice[11];

vector <vector <pair <int, int>>> v;

int blueCheck[41];

pair <int, int> horses[4];

int result = 0;

void makeMap() {
	for (int i = 0; i < 40; i += 2) {
		v[i].push_back(make_pair(0, i + 2));
	}
	for (int i = 10; i <= 16; i+=3) {
		v[i].push_back(make_pair(1, i + 3));
	}
	v[19].push_back(make_pair(1, 25));
	
	v[30].push_back(make_pair(2, 28));
	for (int i = 28; i >= 26; i--) {
		v[i].push_back(make_pair(2, i - 1));
	}

	for (int i = 20; i <= 22; i += 2) {
		v[i].push_back(make_pair(3, i + 2));
	}
	v[24].push_back(make_pair(3, 25));

	for (int i = 25; i <= 35; i += 5) {
		v[i].push_back(make_pair(3, i + 5));
	}
	//v[40].push_back(make_pair(3, 'E'));
	v[40].push_back(make_pair(0, 'E'));

	blueCheck[10] = 1;
	blueCheck[20] = 3;
	blueCheck[30] = 2;
}

pair <int ,int> go(int count, int direction, int currentLocation) {
	if (currentLocation == 25) {
		direction = 3;
	}
	if (currentLocation == 40) {
		direction = 0;
	}
	if (currentLocation == 'E')
		return make_pair(direction, 'E');

	if (count == 0) {
		for (int i = 0; i < 4; i++) {
			if (horses[i].second == currentLocation && horses[i].first == direction) {
				return make_pair(-1, -1);
			}
		}
		return make_pair(direction, currentLocation);
	}

	for (int i = 0; i < v[currentLocation].size(); i++) {
		if (v[currentLocation][i].first == direction) {
			return go(count - 1, direction, v[currentLocation][i].second);
		}
	}
}


void recursion(int index , int value, vector <int> v2) {
	if (index == 10) {
		result = max(result, value);
		if (value == 218) {
			for (int i = 0; i < v2.size(); i++) {
				cout << v2[i] << " ";
			}
			cout << endl;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (horses[i].second == 'E') {
			continue;
		}
		pair <int, int> current = horses[i];

		pair <int, int> tmp;

		if (horses[i].first==0 && blueCheck[horses[i].second] > 0) {
			int next;
			for (int j = 0; j < v[horses[i].second].size(); j++) {
				if (v[horses[i].second][j].first == blueCheck[horses[i].second]) {
					next = v[horses[i].second][j].second;
					break;
				}
			}
			tmp = go(dice[index] - 1, blueCheck[horses[i].second], next);
		}
		else {
			tmp= go(dice[index], horses[i].first, horses[i].second);
		}
		if (tmp.first == -1) {
			continue;
		}
		horses[i] = tmp;

		v2.push_back(i);

		if (tmp.second != 'E') 
			recursion(index + 1, value + tmp.second, v2);
		else
			recursion(index + 1, value, v2);
		v2.pop_back();
		horses[i] = current;
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		scanf("%d", &dice[i]);
	}
	v.resize(41);
	makeMap();
	vector <int> v2;
	recursion(0, 0, v2);
	cout << result;
	//system("Pause");
}