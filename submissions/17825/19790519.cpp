#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector <int> v[5][41];
pair <int, int> blueCheck[41];

pair <int, int> horses[4];

int result = 0;

int input[11];

void makeMap() {

    blueCheck[10] = make_pair(13, 1);
    blueCheck[20] = make_pair(22, 3);
    blueCheck[30] = make_pair(28, 2);

    for (int i = 0; i < 40; i += 2) {
        v[0][i].push_back(i + 2);
    }

    for (int i = 10; i < 19; i += 3) {
        v[1][i].push_back(i + 3);
    }
    v[1][19].push_back(25);


    v[2][30].push_back(28);
    for (int i = 28; i >= 26; i--) {
        v[2][i].push_back(i - 1);
    }


    for (int i = 25; i < 40; i += 5) {
        v[3][i].push_back(i + 5);
    }


    for (int i = 20; i < 24; i += 2) {
        v[3][i].push_back(i + 2);
    }

    v[3][24].push_back(25);


    v[0][40].push_back('E');
    v[3][40].push_back('E');
}



pair <int, int> go(int currentLocation, int count, bool flag, int route) {
    if (currentLocation == 'E') {
        if (flag == true)
            return make_pair(currentLocation, route);
        else
            return make_pair(-1, -1);
    }
    if (count == 0) {
        if (currentLocation != 'E') {
            for (int i = 0; i < 4; i++) {
                if (horses[i].first == currentLocation) {
                    return make_pair(-1, -1);
                }
            }
        }
        return make_pair(currentLocation, route);
    }

    if (flag == false && route == 0 && blueCheck[currentLocation].first > 0) {
        return go(blueCheck[currentLocation].first, count - 1, true, blueCheck[currentLocation].second);
    }

    for (int i = 0; i < v[route][currentLocation].size(); i++) {
        return go(v[route][currentLocation][i], count - 1, true, route);
    }
    for (int r = 0; r < 4; r++) {
        for (int i = 0; i < v[r][currentLocation].size(); i++) {
            return go(v[r][currentLocation][i], count - 1, true, r);
        }
    }

}
void recursion(int i1, int value) {
	if (i1 == 10) {
		result = max(result, value);
		return;
	}
    bool flag = false;
	for (int i = 0; i < 4; i++) {
		pair <int, int> tmp = horses[i];
		pair <int, int> changedLocation = go(tmp.first, input[i1], false, tmp.second);

		if (changedLocation.first == 'E') {
			horses[i] = changedLocation;
            flag = true;
			recursion(i1 + 1, value);
			horses[i] = tmp;
		}
		else if (changedLocation.first > 0) {
			horses[i] = changedLocation;
            flag = true;
			recursion(i1 + 1, value + changedLocation.first);
			horses[i] = tmp;

		}

	}
 

}

int main() {

    for (int i = 0; i < 10; i++) {
        cin >> input[i];
    }
    makeMap();
    recursion(0, 0);
    cout << result;

    //system("Pause");

}


